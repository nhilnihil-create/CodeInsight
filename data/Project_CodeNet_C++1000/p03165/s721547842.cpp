#include <bits/stdc++.h>
using namespace std;

const int N = 3000;

int dp[N + 1][N + 1];

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  s = '$' + s;
  t = '$' + t;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= m; j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (s[i] == t[j]) {
        dp[i][j] = dp[i-1][j-1] + 1;
      } else {
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
      }
    }
  }
  int i = n, j = m;
  string ans = "";
  while (i > 0 && j > 0) {
    if (s[i] == t[j]) {
      ans += s[i];
      i--, j--;
    } else {
      if (dp[i-1][j] > dp[i][j-1]) {
        i--;
      } else {
        j--;
      }
    }
  }
  reverse(ans.begin(), ans.end());
  cout << ans << '\n';
  return 0;
}
