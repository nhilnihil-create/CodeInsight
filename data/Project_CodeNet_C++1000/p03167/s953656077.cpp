#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll H,W;
  cin>>H>>W;
  vector<string> vec(H);
  for(ll i=0;i<H;i++) {
cin>>vec[i];
  }
  
  vector<vector<ll>> dp(H,vector<ll> (W,0));
  dp[H-1][W-1]=1;
  for(ll i=W-2;i>=0;i--) {
if(vec[H-1][i]=='#') {
dp[H-1][i]=0;
}
    else {
dp[H-1][i]=dp[H-1][i+1];
    }
  }
  
  
  for(ll i=H-2;i>=0;i--) {
    if(vec[i][W-1]=='#') {
dp[i][W-1]=0;
    }
    else {
dp[i][W-1]=dp[i+1][W-1];
    }
  }
  
  ll mod=1000000007;
  for(ll i=W-2;i>=0;i--) {
for(ll j=H-2;j>=0;j--) {
if(vec[j][i]=='#') {
dp[j][i]=0;
}
  else {
dp[j][i]=(dp[j+1][i]+dp[j][i+1])%mod;
  }
}
  }
  
  
cout<<dp[0][0]<<endl;


}
  