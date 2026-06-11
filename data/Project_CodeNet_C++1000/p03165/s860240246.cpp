#include <bits/stdc++.h>
using namespace std;
int dp[3000][3000];
int main() {
  string a, b;
  cin >> a >> b;
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b.size(); j++) {
      if (!i && !j)
        dp[i][j] = (a[0] == b[0]);
      else if (!i)
        if (a[i] == b[j])
          dp[i][j] = 1;
        else
          dp[i][j] = dp[i][j - 1];
      else if (!j)
        if (a[i] == b[j])
          dp[i][j] = 1;
        else
          dp[i][j] = dp[i - 1][j];
      else if (a[i] == b[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  int i = a.size() - 1, j = b.size() - 1;
  string res = "";
  while (i != -1 && j != -1) {
    if (a[i] == b[j]) {
      res += a[i];
      i--; j--;
    }
    else if (i && dp[i - 1][j] == dp[i][j])
      i--;
    else
      j--;
  }
  reverse(res.begin(), res.end());
  cout << res;
  return 0;
}