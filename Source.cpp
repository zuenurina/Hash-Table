#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

struct Hash {
    int value[15];
    int index[15];
};

int keyValue(char a) {
    int x = a - 64;
    return x;
}

int main() {
    Hash record;
    Hash coll;
    string key;
    int i, hash, no = 0, update;
    char table[13] = { 0 };
    char collision[13] = { 0 };

    cout << "Enter key: ";
    getline(cin, key);
    //key = "MEDALLA";

    cout << endl << "Original Table: \n";
    for (i = 0; i < key.length(); i++) {
        cout << key[i] << "\t";
    }
    cout << endl;

    for (i = 0; i < key.length(); i++) {
        record.value[i] = keyValue(key[i]);
        cout << record.value[i] << "\t";
    }
    cout << endl << endl;

    cout << "Hash Table: \n";
    for (i = 0; i < key.length(); i++) {
        cout << key[i] << "\t";
    }
    cout << endl;

    for (i = 0; i < key.length(); i++) {
        record.index[i] = record.value[i] % 13;
        cout << record.index[i] << "\t";
    }
    cout << endl << endl;

    for (i = 0; i < key.length(); i++) {
        hash = record.index[i];

        if (table[hash] == 0) {
            table[hash] = key[i];
        }

        else {
            while (table[hash] != 0) {
                int k = 1;
                hash = (hash + k) % 13;
                k++;
            }
            table[hash] = key[i];
        }
    }

    cout << "\nHash Table: " << endl;
    for (int i = 0; i < 13; i++) {
        cout << i << "\t";
    }

    cout << endl;

    for (int i = 0; i < 13; i++) {

        cout << table[i] << "\t";
    }

    cout << endl << endl;

    return 0;
}