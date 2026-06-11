#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  vector<double> vec(N);
  for(ll i=0;i<N;i++) {
cin>>vec[i];
  }
  vector<vector<double>> dp(N+1,vector<double>(N+1,0));
  dp[0][0]=1;
for(ll i=1;i<=N;i++) {
dp[i][0]=dp[i-1][0]*(1-vec[i-1]);
}
  
for(ll i=1;i<=N;i++) {
  for(ll j=1;j<=N;j++) {
    dp[i][j]=dp[i-1][j]*(1-vec[i-1])+dp[i-1][j-1]*vec[i-1];
  }
}
  
  double ans=0;
  for(ll i=N/2+1;i<=N;i++) {
ans+=dp[N][i];
  }
  cout<<fixed<<setprecision(10);
cout<<ans<<endl;
}

  
