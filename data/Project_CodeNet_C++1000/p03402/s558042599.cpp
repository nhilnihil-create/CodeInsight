#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    char v[110][110];
    //黒：'#', 白：'.'
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (i < 50) v[i][j] = '#';
            else v[i][j] = '.';
        }
    }

    for (int i = 0; i < 49 && a > 1; i += 2) {
        for (int j = 0; j < 100 && a > 1; j += 2) {
            v[i][j] = '.';
            a--;
        }
    }
    for (int i = 51; i < 100 && b > 1; i += 2) {
        for (int j = 0; j < 100 && b > 1; j += 2) {
            v[i][j] = '#';
            b--;
        }
    }

    cout << 100 << " " << 100 << endl;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cout << v[i][j];
        }
        cout << endl;
    }

    return 0;
}