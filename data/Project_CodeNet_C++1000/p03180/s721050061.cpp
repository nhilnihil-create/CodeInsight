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

int dp[1 << 16];

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto &it: a) {
        for (int &x: it) {
            cin >> x;
        }
    }
    // var(n);
    // return;
    const int mx = 1 << n;
    var(mx);
    // return;
    for (int mask = 0; mask < mx; mask++) {
        bitset<16> ok(mask);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (ok[i] && ok[j]) {
                    dp[mask] += a[i][j];
                }
            }
        }
    }
    for (int mask = 0; mask < mx; ++mask) {
        for (int s = mask; s > 0; s = (s - 1) & mask) {
            dp[mask] = max(dp[mask], dp[s] + dp[s ^ mask]);
        }
    }
    cout << dp[(1 << n) - 1] << '\n';
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