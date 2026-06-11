#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)
using ll = long long;
int MAX = 2e4;

int main(){
  int n;
  cin >> n;
  int w[n], s[n]; ll v[n];
  rep(i,n) cin >> w[i] >> s[i] >> v[i];
  int ord[n];
  rep(i,n) ord[i] = i;
  sort(ord,ord+n,[&](int a, int b){return w[a]+s[a] < w[b]+s[b];});
  vector<vector<ll>> dp(n+1,vector<ll>(MAX));
  rep(i,n) {
    rep(j,MAX) {
      dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
      if(s[ord[i]] >= j) {
        int wa = min(MAX-1,j+w[ord[i]]);
        dp[i+1][wa] = max(dp[i+1][wa],dp[i][j]+v[ord[i]]);
      }
    }
  }
  ll ans = 0;
  rep(i,MAX) ans = max(ans,dp[n][i]);
  cout << ans << endl;
  return 0;
}