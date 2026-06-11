#include <bits/stdc++.h>

#define int long long

using namespace std;

const int mod = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> dp(2, vector<int>(k + 1, 0));
    dp[0][k] = 1;
    for (int i = 1; i <= n; i++) {
        vector<int> sum(k + 2);
        for (int j = 0; j <= k; j++) {
            sum[j + 1] = sum[j] + dp[(i - 1) % 2][j];
            sum[j + 1] %= mod;
        }
        for (int j = 0; j <= k; j++) {
            dp[i % 2][j] = (sum[min(k, j + a[i - 1]) + 1] - sum[j] + mod) % mod;
        }
    }
    cout << dp[n % 2][0] << endl;
}
