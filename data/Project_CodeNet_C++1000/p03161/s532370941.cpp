  #include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
 ll K;
  cin>>K;
  vector<ll> h(N);
  for(ll i=0;i<N;i++) {
cin>>h[i];
  }
  
  vector<ll> dp(N);
  dp[N-1]=0;
  for(ll i=N-2;i>=0;i--) {
    dp[i]=dp[i+1]+abs(h[i]-h[i+1]);
for(ll j=2;j<=K;j++) {
  if(i+j>N-1) {
break;
  }
  dp[i]=min(dp[i],dp[i+j]+abs(h[i]-h[i+j]));
}
  }
  
  cout<<dp[0]<<endl;
}

  
    
    
    
  
