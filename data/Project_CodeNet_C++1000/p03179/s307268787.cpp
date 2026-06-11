#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

const int mod = 1e9 + 7;

void self_add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

int main() {
  int n;
  string s;
  cin >> n >> s;

  vector<vector<int>> dp(n + 1, vector<int>(n + 1));
  dp[1][1] = 1;
  for (int i = 0; i < n - 1; ++i) {
    int j = i + 2;
    if (s[i] == '<') {
      dp[j][1] = 0;
      for (int k = 2; k <= j; ++k) {
        dp[j][k] = dp[j][k-1];
        self_add(dp[j][k], dp[j-1][k-1]);
      }
    } else {
      dp[j][j] = 0;
      for (int k = j-1; k >= 1; --k) {
        dp[j][k] = dp[j][k+1];
        self_add(dp[j][k], dp[j-1][k]);
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    self_add(ans, dp[n][i]);
  }
  cout << ans << '\n';

  return 0;
}
