 #include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  vector<ll> A(N);
  vector<ll> B(N);
  vector<ll> C(N);
  for(ll i=0;i<N;i++) {
cin>>A[i]>>B[i]>>C[i];
  }
  vector<vector<ll>> dp(N,vector<ll>(3));
  dp[N-1][0]=A[N-1];
  dp[N-1][1]=B[N-1];
  dp[N-1][2]=C[N-1];
  
  for(ll i=N-2;i>=0;i--) {
dp[i][0]=max(dp[i+1][1]+A[i],dp[i+1][2]+A[i]);
    dp[i][1]=max(dp[i+1][0],dp[i+1][2])+B[i];
    dp[i][2]=max(dp[i+1][0],dp[i+1][1])+C[i];
  }
  
  
  ll ans=0;
  for(ll i=0;i<3;i++) {
ans=max(ans,dp[0][i]);
  }
  
  cout<<ans<<endl;
}
