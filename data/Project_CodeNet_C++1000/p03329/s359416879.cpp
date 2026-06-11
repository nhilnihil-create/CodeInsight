#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(n, i) for(int i = 0; i < n; ++i)

const ll INF = 1LL << 60;

void solve(void){
  ll n; cin >> n;

  vector<ll> dp(n+10, INF);
  dp[0] = 0;

  for(ll i = 1; i <= n; ++i) {
    ll power = 1;
    while(power <= i) {
      dp[i] = min(dp[i], dp[i-power] + 1);
      power *= 6;
    }

    ll power2 = 1;
    while(power2 <= i) {
      dp[i] = min(dp[i], dp[i-power2] + 1);
      power2 *= 9;
    }
  }

  cout << dp[n] << endl;
}

int main(void) {
  solve();
  return 0;
}