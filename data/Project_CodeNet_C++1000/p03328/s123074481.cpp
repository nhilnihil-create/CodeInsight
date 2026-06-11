#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using lint = long;
using llint = long long;
using namespace std;

int main() {
    fastIO;
    int a, b;
    cin >> a >> b;

    int diff = b - a;

    int towerL = 1;
    for (int i = 2; i <= 999; i++) {
        if (diff == i) {
            cout << towerL - a << endl;
            return 0;
        }
        towerL += i;
    }
}
