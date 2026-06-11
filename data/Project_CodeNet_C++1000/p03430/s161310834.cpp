#include <bits/stdc++.h>

using namespace std;
const int N = 305;
int dp[N][N][N];

int main()
{
    string s; cin >> s;
    int n = s.size(), k; cin >> k;
    for (int i = 0; i < n; i++) for (int j = 0; j <= k; j++) dp[i][i][j] = 1;
    for (int len = 2; len <= n; len++) {
        for (int l = 0, r = len - 1; r < n; l++,r++) {
            for (int j = 0; j <= k; j++) {
                dp[l][r][j] = max(dp[l+1][r][j], dp[l][r-1][j]);
                if (j - (s[l] != s[r]) >= 0) dp[l][r][j] = max(dp[l][r][j], dp[l+1][r-1][j - (s[l] != s[r])] + 2);
            }
        }
    }
    cout << dp[0][n-1][k] << "\n";
}
