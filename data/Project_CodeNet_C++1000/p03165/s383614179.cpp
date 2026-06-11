#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  string s, t;
  cin >> s >> t;
  int ls = s.size();
  int lt = t.size();
  vector<vector<int>> dp(ls+1, vector<int>(lt+1));
  rep(i, ls+1) rep(j, lt+1) {
    if (i == 0 || j == 0) continue;
    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    if (s[i-1] == t[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
  }
  int l = dp[ls][lt];
  string ans = "";
  int i = ls, j = lt;
  while (l) {
    while (dp[i-1][j] == l) --i;
    while (dp[i][j-1] == l) --j;
    ans += s[i-1];
    --i; --j; --l;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
  return 0;
}