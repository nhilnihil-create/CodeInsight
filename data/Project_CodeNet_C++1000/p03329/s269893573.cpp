#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main(){
  int n;
  cin >> n;
  int INF = 1e5 + 1;
  vector<int> dp(n+10, INF);
  dp[0] = 0;
  rep(i, n){
    int power = 1;
    while(i + power <= n){
      chmin(dp[i + power], dp[i] + 1);
      power *= 6;
    }
    power = 9;
    while(i + power <= n){
      chmin(dp[i + power], dp[i] + 1);
      power *= 9;
    }
  }
  cout << dp[n] << endl;
  return 0;
}