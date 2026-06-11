/**
*    created: 23.05.2020 00:33:32
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << (a - c) * (b - d) << endl;
    return 0;
}