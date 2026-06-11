#include <bits/stdc++.h>
using namespace std;
#define Int int64_t
#define dump(x) cout << (x) << endl
#define fi first
#define se second
Int mod = 1e9+7;
Int INF = 1e18;
double EPS = 0.00000001;
//Int mod = 1e6+3;

int main() {
    Int n;
    cin >> n;
    vector<Int> c(n);
    for (Int i = 0; i < n; i++) cin >> c[i];
    vector<Int> d;
    d.emplace_back(c[0]);
    for (Int i = 1; i < n; i++) {
        if (d.back() == c[i]) continue;
        d.emplace_back(c[i]);
    }
    Int m = (Int)d.size();
    vector<Int> dp(m + 1, 0);
    dp[0] = 1;
    map<Int, Int> mp;
    for (Int i = 0; i < m; i++) {
        dp[i + 1] += mp[d[i]] + dp[i];
        dp[i + 1] %= mod;
        mp[d[i]] = dp[i + 1];
    }
    dump(dp[m]);
    return 0;
}