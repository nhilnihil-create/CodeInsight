#include <iostream>
#include <string>

using namespace std;

const int MAX_N = 305;

int dp [MAX_N][MAX_N][MAX_N];

int main () {
  string s;
  cin >> s;

  int n, K;
  n = s.size();
  cin >> K;

  for (int i = 0; i < n; i++) {
    dp[i][i][0] = 1;
  }
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      dp[i][i + 1][0] = 2;
    } else {
      dp[i][i + 1][1] = 2;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int l = 0; l + i < n; l++) {
      int r = l + i;
      for (int k = 0; k <= K; k++) {
        if (l != 0) dp[l - 1][r][k] = max(dp[l - 1][r][k], dp[l][r][k]);
        if (r != n) dp[l][r + 1][k] = max(dp[l][r + 1][k], dp[l][r][k]);
        if (l != 0 && r != n && s[l - 1] == s[r + 1]) {
          dp[l - 1][r + 1][k] = max(dp[l - 1][r + 1][k], dp[l][r][k] + 2);
        }
        if (l != 0 && r != n) {
          dp[l - 1][r + 1][k + 1] = max(dp[l - 1][r + 1][k + 1], dp[l][r][k] + 2);
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i <= K; i++) {
    ans = max(ans, dp[0][n - 1][i]);
  }
  cout << ans << endl;
}
