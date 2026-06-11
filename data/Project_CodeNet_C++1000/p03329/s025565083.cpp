#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60;
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> dp(21000000);

    for (int i = 0; i < 21000000; i++) dp[i] = INF;

    dp[0] = 0;

    for (ll i = 1; i<=N; i++){
      for (ll j = 1; j<=i; j*=6){
        chmin(dp[i], dp[i - j] + 1);
      }
      for (ll k = 1; k<=i; k*=9){
        chmin(dp[i], dp[i - k] + 1);
      }
    }
    cout << dp[N] << endl;
    return 0;
}