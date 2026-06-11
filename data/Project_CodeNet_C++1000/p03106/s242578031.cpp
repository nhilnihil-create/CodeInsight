/**
*    created: 23.05.2020 01:09:02
**/
#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a, b, k;
    cin >> a >> b >> k;
    int d = __gcd(a,b);
    vector<int> g;
    rep2(i,1,sqrt(d)+1) {
        if (d % i == 0) {
            g.push_back(i);
            if (d / i != i) g.push_back(d / i);
        }
    }
    sort(g.rbegin(), g.rend());
    cout << g[k-1] << endl;
    return 0;
}