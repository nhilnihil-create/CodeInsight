#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vector<double> p(n+1);
  rep(i,n) cin >> p[i+1];
  vector<vector<double>> dp(n+1, vector<double>(n+1));
  dp[1][1] = p[1];
  dp[0][0] = 1;
  for(int i=1; i<=n; i++){
    for(int j=0; j<=n; j++){
      if(i==1 && j==1) continue;
      if(i<j) continue;
      if(j==0) dp[i][0] = dp[i-1][0]*(1-p[i]);
      else dp[i][j] = dp[i-1][j]*(1-p[i]) + dp[i-1][j-1]*p[i]; 
    }
  }
  //rep(i,4) cout << dp[n][i] << endl;
  double ans = 0;
  for(int j = n/2+1; j<=n; j++) ans += dp[n][j];
  printf("%.10f", ans);
}
