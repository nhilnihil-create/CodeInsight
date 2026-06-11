#include <bits/stdc++.h>
using namespace std;
#define int long
const int mod = 1e9 + 7;
signed main() {
    int n;
    cin >> n;
    vector<int> c(n), dp(n, 0);
    for (int& i : c) cin >> i;
    vector<int> stn(2e5 + 5, -1);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        if (i) dp[i] = dp[i - 1];
        if (stn[c[i]] >= 0 && stn[c[i]] + 1 < i) (dp[i] += dp[stn[c[i]]]) %= mod;
        stn[c[i]] = i;
    }
    cout << dp[n - 1];
}