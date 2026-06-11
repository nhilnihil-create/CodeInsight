#include <bits/stdc++.h>

using namespace std;

const int N = 330;

inline void smax(int &x, int y) { if (x < y) x = y; }

int dp[N][N][N];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = (int) s.size();
  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }
  for (int i = 1; i <= n; i++) {
    dp[i][i][0] = 1;
    if (i < n && s[i - 1] == s[i]) {
      dp[i][i + 1][0] = 2;
    } else if (i < n) {
      dp[i][i + 1][1] = 2;
    }
  }
  for (int i = n; i >= 1; i--) {
    for (int j = i + 1; j <= n; j++) {
      for (int r = 0; r <= k; r++) {
        smax(dp[i][j][r], dp[i + 1][j][r]);
        smax(dp[i][j][r], dp[i][j - 1][r]);
        smax(dp[i][j][r], dp[i][j][r - 1]);
        if (s[i - 1] == s[j - 1]) {
          smax(dp[i][j][r], dp[i + 1][j - 1][r] + 2);
        } else if (r > 0) {
          smax(dp[i][j][r], dp[i + 1][j - 1][r - 1] + 2);
        }
      }
    }
  }
  cout << dp[1][n][k] << '\n';
  return 0;
}
