#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define mod 1000000007

int main(){
  ll n;
  cin>>n;
  vector<ll>v;
  ll x;
  ll psum[n];
  for(ll i=0; i<n; i++){
    cin>>x;
    v.push_back(x);
  }
  psum[0]=v[0];
  for(ll i=1; i<n; i++){
    psum[i]= psum[i-1]+v[i];
  }
  ll dp[n][n];
  memset(dp,0,sizeof(dp));
  for(ll i=0; i<n; i++){
    dp[i][i] =0;
  }
  ll j;
  ll mval;
  for(ll ln=2; ln<=n; ln++){
    for(ll i=0; i<n+1-ln; i++){
      j = i+ln-1;
      dp[i][j] = 1e18;
      for(ll k=i; k<j; k++){
        mval = i==0?dp[i][k] + dp[k+1][j] + psum[j] : dp[i][k] + dp[k+1][j] + psum[j]-psum[i-1];
        if(mval<dp[i][j]){
          dp[i][j] = mval;
        }
      }
      
    }
  }
  cout<<dp[0][n-1]<<"\n";
  return 0;
}
