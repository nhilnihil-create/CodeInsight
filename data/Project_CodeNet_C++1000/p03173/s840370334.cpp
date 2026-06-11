#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

int main() {

  ll N;
  cin>>N;
  vector<ll> A(N);
  for(ll i=0;i<N;i++) {
cin>>A[i];
  }
  
 vector<ll> r(N+1);
  r[0]=0;
 ll sum=0;
  for(ll i=0;i<N;i++) {
sum+=A[i];
    r[i+1]=sum;
  }
  
  vector<vector<ll>> dp(N+1,vector<ll> (N+1,0));
  
  for(ll i=2;i<=N;i++) {
for(ll j=0;j+i<N+1;j++) {
ll p=r[j+i]-r[j];
  ll s=100000000000000007;
  for(ll h=j+1;h<j+i;h++) {
    s=min(s,dp[j][h]+dp[h][j+i]);
  }
  dp[j][j+i]=p+s;
}
  }
  
  cout<<dp[0][N]<<endl;
}

  
  
  
  
  