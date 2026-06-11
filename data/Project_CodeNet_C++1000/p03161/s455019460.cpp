#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N,M;
  cin >> N >> M;
  vector<ll> flog(N);
  for(ll i=0;i<N;i++){
    cin >> flog[i];
  }
  ll inf=pow(10,10);
  vector<ll> dp(N,inf);
  dp[0]=0;
  for(ll i=0;i<N;i++){
    for(ll j=1;j<=M;j++){
      if(i+j>=N){
        break;
      }
      else{
        dp[i+j]=min(dp[i]+abs(flog[i]-flog[i+j]),dp[i+j]);
      }
    }
  }
  cout << dp[N-1] <<endl;
}

