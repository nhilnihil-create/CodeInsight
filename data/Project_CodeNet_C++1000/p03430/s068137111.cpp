#include <bits/stdc++.h>
#define FOR(i,k,n)  for(int i = (k);i < (n);++i)
#define REP(i,n)    FOR(i,0,n)
#define ALL(x)      begin(x),end(x)

using namespace std;
using vecint = vector<int>;
using ll = int64_t;

int main()
{
  string s;
  cin>>s;
  string r = s;
  reverse(ALL(r));
  int n = s.size();
  int K;
  cin>>K;
  vector<vector<vecint>> dp(n+1, vector<vecint>(n+1, vecint(K+1, 0)));
  REP(i,n)REP(j,n)REP(k,K+1) {
    //cerr << i << ' ' << j << ' ' << k << ' ' << dp[i][j][k] << endl;
    if (s[i] == r[j]) {
      dp[i+1][j+1][k] = max(dp[i+1][j+1][k], 1 + dp[i][j][k]);
    }
    if (k<K) {
      dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k+1], 1 + dp[i][j][k]);
    }
    dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
    dp[i][j+1][k] = max(dp[i][j+1][k], dp[i][j][k]);
    dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k]);
  }
  int mx = 0;
  REP(i,n)REP(j,n) {
    if (i+j > n) break;
    mx = max(mx, dp[i][j][K]*2+(n-(i+j))%2);
  }
  cout << mx << endl;
  return 0;
}
