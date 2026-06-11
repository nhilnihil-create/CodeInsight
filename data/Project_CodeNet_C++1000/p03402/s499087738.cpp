// ABC092 - D
// Grid Components

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;

    vector<vector<char>> table(100, vector<char>(100));
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (i < 50) table[i][j] = '.';
            else table[i][j] = '#';
        }
    }

    for (int b = 0; b < B - 1; ++b) {
        int i = b / 50;
        i *= 2;
        int j = (b % 50) * 2;
        table[i][j] = '#';
    }

    for (int a = 0; a < A - 1; ++a) {
        int i = a / 50;
        i *= 2;
        i += 51;
        int j = (a % 50) * 2;
        table[i][j] = '.';
    }

    cout << 100 << ' ' << 100 << endl;
    for (int i = 0; i < 100; ++i) {
        for (int j = 0; j < 100; ++j) {
            cout << table[i][j];
        }
        cout << endl;
    }
}