#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  ll n;
  cin >> n;
  vector<ll> h(n);
  rep(i,n){
    cin >> h.at(i);
  }
  ll dp[n+1];
  dp[1]=0;
  for(ll i=1;i<n;i++){
    if(i==1){
      dp[2]=abs(h.at(i)-h.at(i-1));
    }else{
      dp[i+1]=min(dp[i]+abs(h.at(i)-h.at(i-1)),dp[i-1]+abs(h.at(i)-h.at(i-2)));
    }
  }
  cout << dp[n];
}
