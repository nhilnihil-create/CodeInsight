#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int x[n], y[n];
    cin >> x[0] >> y[0];
    int odd = ((x[0] + y[0]) % 2 + 2) % 2;
    if (!odd) {
        x[0]--;
    }
    for (int i = 1; i < n; i++) {
        cin >> x[i] >> y[i];
        if (((x[i] + y[i]) % 2 + 2) % 2 != odd) {
            odd = -1;
            break;
        }
        if (!odd) {
            x[i]--;
        }
    }

    if (odd == -1) {
        cout << -1 << endl;
        return 0;
    }

    int m = 31 + (!odd);
    cout << m << endl;
    int d[m];
    for (int i = 0; i <= 30; i++) {
        d[i] = 1 << (30 - i);
    }
    if (!odd) {
        d[31] = 1;
    }
    for (int i = 0; i < m; i++) {
        cout << d[i] << (i == m - 1 ? '\n' : ' ');
    }

    for (int i = 0; i < n; i++) {
        int a = x[i], b = y[i];
        int as = a >= 0 ? 1 : -1, bs = b >= 0 ? 1 : -1;
        a *= as, b *= bs;

        for (int j = 0; j <= 30; j++) {
            char c;
            if (a >= b) {
                c = as == 1 ? 'R' : 'L';
                if (a >= d[j]) {
                    a -= d[j];
                } else {
                    a = d[j] - a;
                    as = -as;
                }
            } else {
                c = bs == 1 ? 'U' : 'D';
                if (b >= d[j]) {
                    b -= d[j];
                } else {
                    b = d[j] - b;
                    bs = -bs;
                }
            }

            cout << c;      
        }

        if (!odd) {
            cout << "R";
        }
        cout << endl;
    }

    return 0;
}