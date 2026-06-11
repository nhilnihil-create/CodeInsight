/**
*    created: 13.05.2020 19:39:53
**/
#include <bits/stdc++.h>
#define int long long
const int INF = 1e18L + 5;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int r, d, x;
    cin >> r >> d >> x;
    rep(i,10) {
        x = r * x - d;
        cout << x << endl;
    }
    return 0;
}