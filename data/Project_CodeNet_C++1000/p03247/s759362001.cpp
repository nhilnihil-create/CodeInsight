#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int *x = new int[n];
    int *y = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cin >> y[i];
    }

    bool odd;
    if ((x[0] + y[0]) % 2 == 0) {
        odd = false;
        x[0]++;
    }
    else odd = true;

    if (odd) {
        for (int i = 1; i < n; i++) {
            if ((x[i] + y[i]) % 2 == 0) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    else {
        for (int i = 1; i < n; i++) {
            if ((x[i] + y[i]) % 2 == 1) {
                cout << -1 << endl;
                return 0;
            }
            x[i]++;
        }
    }

    if (odd) cout << 31 << endl;
    else cout << 32 << endl;

    for (int i = 30; i > 0; i--) cout << (1 << i) << " ";
    cout << 1;
    if (!odd) cout << " 1";
    cout << endl;

    for (int i = 0; i < n; i++) {
        int p = x[i];
        int q = y[i];

        for (int j = 30; j >= 0; j--) {
            int t = 1 << j;
            if (abs(p) > abs(q)) {
                if (p > 0) {
                    p -= t;
                    cout << "R";
                }
                else {
                    p += t;
                    cout << "L";
                }
            }
            else {
                if (q > 0) {
                    q -= t;
                    cout << "U";
                }
                else {
                    q += t;
                    cout << "D";
                }
            }
        }
        if (!odd) cout << "L";
        cout << endl;
    }

    return 0;
}