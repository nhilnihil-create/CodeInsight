#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define double long double
#define pii pair<int, int>
#define FOR(i, a, b) for(int i = a; i < (int)(b); ++i)
#define all(x) x.begin(), x.end()
const int mod = 1000 * 1000 * 1000 + 7;
using namespace std;

double d[301][301][301];

int32_t main() {
    int n;
    cin >> n;  
    int od = 0, dv = 0, t = 0, a;
    FOR(i, 1, n + 1) {
        cin >> a;
        if (a == 1) {
            ++od;
        }
        else if (a == 2) {
            ++dv;
        }
        else {
            ++t;
        }
    }

    FOR(z, 0, n + 1) {
        FOR(y, 0, n + 1) {
            FOR(x, 0, n + 1) {
                d[z][y][x] = n;
                if (!(z || y || x)) {
                    d[z][y][x] = 0;
                    continue;
                }
                if (x) {
                    d[z][y][x] += d[z][y][x - 1] * x;
                }
                if (y && x != n) {
                    d[z][y][x] += d[z][y - 1][x + 1] * y;
                }
                if (z && y != n) {
                    d[z][y][x] += d[z - 1][y + 1][x] * z;
                }
                d[z][y][x] /= (x + y + z);
                // cout << d[z][y][x] << " ";
            }
            // cout << endl;
        }
        // cout << endl;
    }
    cout << fixed << setprecision(10) << d[t][dv][od];
    return 0;
}