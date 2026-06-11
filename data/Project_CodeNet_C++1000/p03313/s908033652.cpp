#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
using P = pair<int,int>;
const int INF = 1e9;

P merge(P p, P q) {
  int a[4] = {p.first,p.second,q.first,q.second};
  sort(a,a+4,greater<int>());
  return P(a[0],a[1]);
}

int main(){
  int n;
  cin >> n;
  int a[1<<n];
  rep(i,1<<n) cin >> a[i];
  vector<vector<P>> dp(1<<n,vector<P>(n+1));
  rep(i,1<<n) dp[i][0] = P(a[i],-INF);
  rep(j,n) {
    rep(i,1<<n) {
      if(i & (1<<j)) dp[i][j+1] = merge(dp[i][j],dp[i^(1<<j)][j]);
      else dp[i][j+1] = dp[i][j];
    }
  }
  int ans = 0;
  for(int i = 1; i < (1<<n); i++) {
    ans = max(ans,dp[i][n].first+dp[i][n].second);
    cout << ans << endl;
  }
  return 0;
}
