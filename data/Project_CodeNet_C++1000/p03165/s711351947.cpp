#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int INF = 2e9;

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size(), m = t.size();
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (s[i] == t[j]) dp[i + 1][j + 1] = max(dp[i][j] + 1, dp[i + 1][j + 1]);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);
    }
  }

  string res = "";
  int i = n, j = m;
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j]) i--;
    else if (dp[i][j] == dp[i][j - 1]) j--;
    else {
      res += s[i - 1];
      i--;
      j--;
    }
  }
  reverse(res.begin(), res.end());
  cout << res << endl;
  return 0;
} 