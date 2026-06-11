#include <bits/stdc++.h>
using namespace std;

int dp[400][400][400];

int main() {
  string s;
  cin >> s;

  int K;
  cin >> K;

  for (int i = 0; i < s.size(); ++i) {
    dp[i][i][0] = 1;
  }

  int ans = 1;
  for (int d = 1; d < s.size(); ++d) {
    for (int l = 0; l + d < s.size(); ++l) {
      int r = l + d;
      for (int k = 0; k <= K; ++k) {
        if (s[l] == s[r]) {
          dp[l][r][k] = max(dp[l][r][k], dp[l + 1][r - 1][k] + 2);
        } else {
          if (k) dp[l][r][k] = max(dp[l][r][k], dp[l + 1][r - 1][k - 1] + 2);
        }

        dp[l][r][k] = max({dp[l][r][k], dp[l + 1][r][k], dp[l + 1][r - 1][k], dp[l][r - 1][k]});
        ans = max(ans, dp[l][r][k]);
      }
    }
  }

  cout << ans << endl;
}
