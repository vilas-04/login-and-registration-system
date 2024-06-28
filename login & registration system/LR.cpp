#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class UserSystem {
public:
    void registerUser() {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        ofstream outFile("users.txt", ios::app);
        if (outFile.is_open()) {
            outFile << username << " " << password << endl;
            outFile.close();
            cout << "Registration successful!" << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    bool loginUser() {
        string username, password, storedUser, storedPass;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        ifstream inFile("users.txt");
        if (inFile.is_open()) {
            while (inFile >> storedUser >> storedPass) {
                if (storedUser == username && storedPass == password) {
                    cout << "Login successful!" << endl;
                    inFile.close();
                    return true;
                }
            }
            inFile.close();
            cout << "Invalid username or password." << endl;
            return false;
        } else {
            cout << "Unable to open file for reading." << endl;
            return false;
        }
    }
};

int main() {
    UserSystem system;
    int choice;

    while (true) {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system.registerUser();
                break;
            case 2:
                system.loginUser();
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

