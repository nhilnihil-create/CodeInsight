#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0;i < (int)(n);i++)
int main() {
  string s, t, ans;cin >> s >> t;
  int m = s.size(), n = t.size();
  vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
  rep(i, m) rep(j, n){
    if(s[i] == t[j]) dp[i+1][j+1] = dp[i][j]+1;
    else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
  }
  int l = dp[m][n];
  m--;n--;
  while(l > 0){
    if(s[m] == t[n]){
      ans = s[m] + ans;
      m--;
      n--;
      l--;
    } else if(dp[m+1][n+1] == dp[m][n+1]) {
      m--;
    } else {
      n--;
    }
  }
  cout << ans << endl;
}