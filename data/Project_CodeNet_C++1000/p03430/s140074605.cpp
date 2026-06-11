#include <bits/stdc++.h>
using namespace std;

int dp[310][310][310];

int main() {
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();
    for (int i = 0; i < n; i++) {
        dp[i][i+1][0] = 1;
        if (i) {
            if (s[i-1] == s[i]) dp[i-1][i+1][0] = 2;
            else {
                dp[i-1][i+1][1] = 2;
                dp[i-1][i+1][0] = 1;
            }
        }
    }
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i < n-len+1; i++) {
            for (int u = 0; u <= 300; u++) {
                // dp[i][i+len][u]
                if (u) dp[i][i+len][u] = max(dp[i][i+len][u], dp[i+1][i+len-1][u-1] + 2);
                dp[i][i+len][u] = max(dp[i][i+len][u], dp[i+1][i+len-1][u] + 2 * (s[i] == s[i+len-1]));
                dp[i][i+len][u] = max({dp[i][i+len][u], dp[i][i+len-1][u], dp[i+1][i+len][u]});
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j <= n; j++) {
            for (int z = 0; z <= k; z++) {
                ans = max(ans, dp[i][j][z]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}