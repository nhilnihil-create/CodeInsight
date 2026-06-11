/**
*    created: 21.06.2020 00:22:50
**/
#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define mod 1000000007
#define pi acos(-1.0)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, yen;
    cin >> n >> yen;
    int man = yen / 10000;
    int gos = yen / 5000;
    rep(x,man+1) {
        rep(y,gos+1) {
            int z = n - x - y;
            if (z < 0) break;
            if (10000 * x + 5000 * y + 1000 * z == yen) {
                cout << x << " " << y << " " << z << endl;
                return 0;
            }
        }
    }
    cout << -1 << " " << -1 << " " << -1 << endl;
    return 0;
}