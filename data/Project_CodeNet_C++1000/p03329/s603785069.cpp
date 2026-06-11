#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

const ll INF = 1LL << 60;

int main() {
  int n;
  cin >> n;
  vector<ll> dp(n + 1, INF);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    chmin(dp[i], dp[i - 1] + 1);
    for (int j = 6; i - j >= 0; j *= 6) {
      chmin(dp[i], dp[i - j] + 1);
    }
    for (int j = 9; i - j >= 0; j *= 9) {
      chmin(dp[i], dp[i - j] + 1);
    }
  }
  cout << dp[n] << endl;
  return 0;
}
