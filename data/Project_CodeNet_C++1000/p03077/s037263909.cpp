/**
*    created: 23.05.2020 00:08:27
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;
    int t = min({a,b,c,d,e});
    if (n % t == 0) cout << n/t + 4 << endl;
    else cout << n/t + 5 << endl;
    return 0;
}