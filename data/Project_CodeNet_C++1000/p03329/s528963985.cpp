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

int main() {
  int n; cin >> n;

// 無限大の値
  const long long INF = 1LL << 60;

// DP テーブル
  long long dp[100010];

// DP テーブル全体を初期化 (最小化問題なので INF に初期化)
  for (int i = 0; i < 100010; ++i) dp[i] = INF;

// 初期条件
  dp[0] = 0;
  int power;

// ループ
  for (int i = 1; i <= n; i++) {
      power = 1;
      while(power <= i){
        chmin( dp[i], dp[i-power]+1 );
        power *= 6;
      }
      power = 1;
      while(power <= i){
        chmin( dp[i], dp[i-power]+1 );
        power *= 9;
      }
  }

// 解を得て出力
  cout << dp[n] << endl;
  
}