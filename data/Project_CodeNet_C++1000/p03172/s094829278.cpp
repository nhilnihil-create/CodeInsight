#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

int main() {
  ll N,K;
  cin>>N>>K;
  ll mod=1000000007;
  vector<ll> A(N);
  for(ll i=0;i<N;i++) {
    cin>>A[i];
  }
  
  vector<vector<ll>> dp(N+1,vector<ll>(K+1));
  for(ll i=0;i<=N;i++) {
dp[i][0]=1;
  }
  
  
  for(ll i=N-1;i>=0;i--) {
    vector<ll> r(K+1);
    r[0]=1;
    
for(ll j=1;j<=K;j++) {
  r[j]=(r[j-1]+dp[i+1][j])%mod;
  dp[i][j]=r[j];
  if(A[i]<j) {
dp[i][j]-=r[j-A[i]-1];
    dp[i][j]%=mod;
  }
}
  }
  
  if(dp[0][K]<0) {
dp[0][K]+=mod;
  }
  cout<<dp[0][K]<<endl;
}

  
  
  
  
