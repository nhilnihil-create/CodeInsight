#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    llint d, n;
    cin >> d >> n;

    // corner
    if (n == 100) {
        if (d == 0)
            cout << 101;
        else if (d == 1)
            cout << 10100;
        else
            cout << 1010000;

    } else if (d == 0)
        cout << n;
    else {
        llint div = pow(100, d);
        cout << div * n;
    }
}