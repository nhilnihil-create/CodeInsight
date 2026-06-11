#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
  ll n;
  cin>>n;
  double p[n+1];
  for(ll i=1; i<=n; i++){
    cin>>p[i];
  }
  double dp[n+1][n+1];
  memset(dp,0.0, sizeof(dp));
  dp[0][0]=1.0;
  for(ll i=1; i<=n; i++){
    for(ll j=0; j<=i; j++){
      if(j==0){
        dp[i][j] = dp[i-1][j]*(1.0-p[i]);
      }
      else{
        dp[i][j] = dp[i-1][j]*(1.0-p[i]) + dp[i-1][j-1]*p[i];
      }
    }
  }
  double ans=0.0;
  for(ll i = (n+1)/2; i<=n; i++){
    ans += dp[n][i];
  }
  cout<<std::setprecision(10) <<ans<<"\n";
  return 0;
}
