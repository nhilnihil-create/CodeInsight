  #include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  vector<ll> h(N);
  for(ll i=0;i<N;i++) {
cin>>h[i];
  }
  
  vector<ll> dp(N,0);
  dp[N-2]=abs(h[N-1]-h[N-2]);
  for(ll i=N-3;i>=0;i--) {
dp[i]=min(dp[i+1]+abs(h[i]-h[i+1]),dp[i+2]+abs(h[i]-h[i+2]));
  }
  
  cout<<dp[0]<<endl;
}

  

    
    
    
    
  
