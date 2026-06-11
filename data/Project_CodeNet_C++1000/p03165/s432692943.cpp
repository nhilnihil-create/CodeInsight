#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <string>
using namespace std;

int main() {
  string s, t;
  cin >> s >> t;
  int n = s.length(), m = t.length();
  vector<vector<int>> dp(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (s[i] == t[j]) {
        dp[i][j] = (i > 0 && j > 0 ? dp[i-1][j-1]: 0) + 1;
      } else {
        dp[i][j] = max((i > 0 ? dp[i-1][j]: 0), (j > 0 ? dp[i][j-1]: 0));
      }
    }
  }
  string ans = "";
  int i = n-1, j = m-1;
  while (i >= 0 && j >= 0 && dp[i][j] > 0) { 
    if (s[i] == t[j]) {
      ans += s[i];
      --i; --j;
    } else {
      if (i > 0 && dp[i-1][j] == dp[i][j]) {
        --i;
      } else {
        --j;
      }
    }
  }
  reverse(ans.begin(), ans.end());
  cout <<  ans << '\n';

  return 0;
}
