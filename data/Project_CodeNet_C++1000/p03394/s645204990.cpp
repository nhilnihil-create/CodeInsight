#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    if (n == 3) { cout << "2 5 63\n"; return 0; }
    if (n == 4) { cout << "2 3 4 9\n"; return 0; }
    if (n == 5) { cout << "2 3 4 6 9\n"; return 0; }
    if (n == 6) { cout << "2 3 4 8 9 10\n"; return 0; }
    if (n == 7) { cout << "2 3 4 6 8 9 10\n"; return 0; }
    cout << "2 3 4 6 8 9 10 ";
    for (int k = 1; k < n/8; k++) {
        cout << 12*k << ' ' << 12*k + 2 << ' ' << 12*k + 3 << ' ' << 12*k + 4 << ' '
             << 12*k + 6 << ' ' << 12*k + 8 << ' ' << 12*k + 9 << ' ' << 12*k + 10 << ' ';
    }
    int r[8][10] = { {0}, {2, 4}, {0, 2, 4}, {2, 4, 8, 10}, {0, 2, 4, 8, 10},
                     {2, 3, 4, 8, 9, 10}, {0, 2, 3, 4, 8, 9, 10},
                     {0, 2, 3, 4, 6, 8, 9, 10} };
    for (int i = 0; i <= n%8; i++) cout << 12*(n/8) + r[n%8][i] << ' ';
    cout << endl;
}
