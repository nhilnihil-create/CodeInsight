#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  ll n;
  cin >> n;

  V<int> can = {1};
  ll t = 1;
  while (true) {
    t *= 6;
    if (t > n) break;
    can.push_back(t);
  }
  t = 1;
  while (true) {
    t *= 9;
    if (t > n) break;
    can.push_back(t);
  }

  V<int> dp(n + 1, n);
  dp[0] = 0;
  rep(i, n) {
    for (auto c : can) {
      if (i + c > n) continue;
      dp[i + c] = min(dp[i] + 1, dp[i + c]);
    }
  }

  cout << dp[n] << endl;
}
