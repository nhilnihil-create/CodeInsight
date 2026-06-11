#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n,k;
  cin >> n>> k;
  vector<ll> h(n+1);
  for(ll i=1;i<=n;i++){
    cin >> h.at(i);
  }
  ll dp[n+1];
  dp[1]=0;
  rep(i,n+1){
    dp[i]=0;
  }
  for(ll i=2;i<=n;i++){
    dp[i]=dp[i-1]+abs(h.at(i)-h.at(i-1));
    for(ll j=1;j<=k;j++){
      if(i-j>=1){
        dp[i]=min(dp[i],dp[i-j]+abs(h.at(i)-h.at(i-j)));
      }
    }
  }
  cout << dp[n];
}