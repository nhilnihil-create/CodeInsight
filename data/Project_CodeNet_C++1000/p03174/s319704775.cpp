#include "bits/stdc++.h"

#define int long long

using namespace std;

const int mod = 1e9 + 7;

int32_t main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> dp(1 << n, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            if (__builtin_popcount(mask) != i) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if ((mask & (1 << j)) == 0 && a[i][j]) {
                    dp[mask | (1 << j)] += dp[mask];
                    dp[mask | (1 << j)] %= mod;
                }
            }
        }
    }
    cout << dp[(1 << n) - 1] << endl;
    return 0;
}
