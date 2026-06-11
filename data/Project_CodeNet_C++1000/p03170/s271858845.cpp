#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()

int main() {
  ll N,K;
  cin>>N>>K;
  vector<ll> vec(N);
  for(ll i=0;i<N;i++) {
cin>>vec[i];
  }
  
vector<bool>dp(K+1);
  dp[0]=false;
  
  for(ll i=1;i<=K;i++) {
for(ll j=0;j<N;j++) {
  
  if(i-vec[j]>=0&&!dp[i-vec[j]]) {
dp[i]=true;
  }
                      }
                      }
                      
                      
                      if(dp[K]) {
cout<<"First"<<endl;
                      }
                      else {
cout<<"Second"<<endl;
                      }
                      }

  
  
