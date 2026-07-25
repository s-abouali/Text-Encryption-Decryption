#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int key) {
    for (char &c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = (c - base + key) % 26 + base;
        }
    }
    return text;
}

string decrypt(string text, int key) {
    return encrypt(text, 26 - (key % 26));
}

int main() {
    int choice, key;
    string message;

    cout << "===== Caesar Cipher =====\n";
    cout << "1. Encrypt\n";
    cout << "2. Decrypt\n";
    cout << "Choose: ";
    cin >> choice;

    cout << "Enter key (1-25): ";
    cin >> key;
    cin.ignore();

    cout << "Enter message: ";
    getline(cin, message);

    if (choice == 1) {
        cout << "\nEncrypted Message:\n";
        cout << encrypt(message, key) << endl;
    } else if (choice == 2) {
        cout << "\nDecrypted Message:\n";
        cout << decrypt(message, key) << endl;
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}
