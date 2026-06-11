// DP

#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {  a = b;  return true;  }
      return false;
    }
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {  a = b;  return true;  }
      return false;
    }

long long dp[100010][3];

int main() {
  int n; cin >> n;
  int A[100010][3];
  rep(i,n) cin >> A[i][0] >> A[i][1] >> A[i][2];


  for (int i = 0; i < n; i++) {
    for(int j = 0; j < 3; j++) {
      for(int k = 0; k < 3; k++) {
        if(j != k)
        chmax( dp[i+1][k], dp[i][j] + A[i][k] );
      }
    }
  }
  cout << max( dp[n][0], max(dp[n][1],dp[n][2]) ) << endl;  
}