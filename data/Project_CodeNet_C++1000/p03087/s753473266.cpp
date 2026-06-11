#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for (ll i = 0; i < (n); ++i)

int main(){
  ll n,q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<ll> dp(n,0);
  
  rep(i,n-1){
    if(s[i] == 'A' && s[i+1] == 'C'){
      dp[i+1] = dp[i]+1;
    }else{
      dp[i+1] = dp[i];
    }
  }
  
  /*
  rep(i,n){
    cout << i << " " << dp[i] << endl;
  }
  */
  
  rep(i,q){
    ll l,r;
    cin >> l >> r;
    l--;
    r--;
    cout << dp[r] - dp[l] << endl;
  }
  
  return(0);
}
