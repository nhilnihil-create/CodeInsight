#include <bits/stdc++.h>

using namespace std;

const int inf = (int) 1e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  string s;
  int t;
  cin >> s >> t;
  int n = (int) s.size();
  vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(t + 2, 0)));
  for (int len = 1; len <= n; len++) {
    for (int i = 0; i + len <= n; i++) {
      for (int k = 0; k <= t; k++) {
        int j = i + len - 1;
        dp[i][j][k] = max(dp[i][j][k], max(dp[i + 1][j][k], j - 1 < 0 ? 0 : dp[i][j - 1][k]));
        if (s[i] == s[j]) {
          dp[i][j][k] = max(dp[i][j][k], 1 + (i < j) + (j - 1 < 0 ? 0 : dp[i + 1][j - 1][k]));
          dp[i][j][k + 1] = max(dp[i][j][k + 1], dp[i][j][k]);
        } else {
          dp[i][j][k + 1] = max(dp[i][j][k + 1], 2 + (j - 1 < 0 ? 0 : dp[i + 1][j - 1][k]));
        }
      }
    }
  }
  cout << dp[0][n - 1][t] << '\n'; 
  return 0;
}