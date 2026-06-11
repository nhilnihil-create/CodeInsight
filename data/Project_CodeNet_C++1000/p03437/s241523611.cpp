#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;

    llint x, y;
    cin >> x >> y;
    if (x % y == 0)
        cout << -1;
    else {
        for (llint i = 1;; i++) {
            llint p = x * i;
            if (p % x == 0 && p % y != 0) {
                cout << p;
                return 0;
            }
        }
    }
}