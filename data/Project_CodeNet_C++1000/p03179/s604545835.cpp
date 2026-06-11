#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> dp(n + 1, vector<int>(n));
    dp[1][0] = 1;
    for (int i = 1; i < n; i++) {
        vector<int> sum(n + 1);
        for (int j = 0; j < n; j++) {
            sum[j + 1] = sum[j] + dp[i][j];
            sum[j + 1] %= mod;
        }
        for (int j = 0; j < i + 1; j++) {
            if (s[i - 1] == '<') {
                dp[i + 1][j] = sum[j];
            } else {
                dp[i + 1][j] = (sum[n] - sum[j] + mod) % mod;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j < n; j++) {
        ans += dp[n][j];
        ans %= mod;
    }
    cout << ans << endl;
}
