// DP

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; ++i)

template<class T> inline bool chmin(T& a, T b) { if (a > b) {  a = b;  return true;  } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) {  a = b;  return true;  } return false; }


ll A[100010][3];

int main() {
  int n; cin >> n;
  rep(i,n){ rep(j,3) cin >> A[i][j]; }
  
  ll dp[100010][3];
  rep(i,100010){  
    rep(j,3){ 
      dp[i][j] = 0;
    }
  }

  rep(i,n) {
    rep(j,3) {
      rep(k,3) {
        if(j == k) continue;
        chmax( dp[i+1][k], dp[i][j] + A[i][k] );
      }
    }
  }
  ll ans = 0;
  rep(j,3) chmax(ans, dp[n][j]);
  cout << ans << endl;
}