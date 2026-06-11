#include <bits/stdc++.h>
#include "bits/stdc++.h"

using namespace std;

#define int long long

#ifndef bhupixb
    #define var(...)
    #define stl(...)
#endif

#define rep(i,a,b) for (int i = a; i <= (int)b; ++i)
#define f first
#define s second

#define single_test

const int maxn = 404;
int dp[maxn][maxn];
int psum[maxn][maxn];
const int inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    rep(i,1,n) {
        rep(j,i,n) psum[i][j] = pre[j] - pre[i - 1];
    }
    rep(len, 2, n) {
        for (int i = 1; i + len - 1 <= n; ++i) {
            int j = i + len - 1;
            int ans = inf;
            for (int k = i; k < j; ++k) {
                ans = min(ans, dp[i][k] + dp[k+1][j] + psum[i][j]);
            }
            dp[i][j] = ans;
        }
    }
    cout << dp[1][n] << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    #ifndef single_test
        cin >> t;
    #endif
    for (int i = 1; i <= t; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}