#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...) 0
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int m = 1 << n;
    vector<int> a(m);
    vector<pair<int, int>> dp(m);
    rep(i, 0, m) {
        cin >> a[i];
        dp[i].first = a[i];
    }
    rep(i, 0, n) {
        rep(b, 0, m) {
            if ((b >> i) & 1) {
                if (dp[b].first <= dp[b ^ (1 << i)].first) {
                    dp[b].second = max(dp[b].first, dp[b ^ (1 << i)].second);
                    dp[b].first = dp[b ^ (1 << i)].first;
                } else {
                    dp[b].second = max(dp[b].second, dp[b ^ (1 << i)].first);
                }
            }
        }
    }
    int ans = 0;
    rep(i, 0, m) {
        ans = max(ans, dp[i].first + dp[i].second);
        if (i) cout << ans << ' ';
    }
    cout << endl;
    //debug(dp);
    return 0;
}