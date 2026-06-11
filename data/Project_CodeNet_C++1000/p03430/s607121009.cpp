#include <bits/stdc++.h>

using namespace std;

const int MAX_S = 300;
const int MAX_K = MAX_S;
int64_t dp[MAX_S+2][MAX_S+2][MAX_K+1];

int main()
{
  string s;
  int k;
  cin >> s >> k;

  s = "0" + s;

  int n = s.size() - 1;

  for (int l = 0; l < n+2; l++)
    for (int r = 0; r < n+2; r++)
      for (int c = 0; c <= k; c++)
        dp[l][r][c] = 0;

  for (int l = n; l > 0; l--) {
    for (int r = l; r <= n; r++) {
      for (int c = 0; c <= k; c++) {
        if (s[l] == s[r])
          dp[l][r][c] = dp[l+1][r-1][c] + (l == r ? 1 : 2);
        dp[l][r][c] = max(dp[l][r][c], max(dp[l+1][r][c], dp[l][r-1][c]));
          if (c != 0)
            dp[l][r][c] = max(dp[l][r][c], dp[l+1][r-1][c-1] + (l == r ? 1 : 2));
      }
    }
  }
  cout << dp[1][n][k] << endl;
  
  return 0;
}
