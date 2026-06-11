#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[55][2];

int main() {
  ll n,k;
  cin >> n >> k;

  vector<ll> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  vector<ll> cnt(50);
  for (int i = 0; i < n; i++) {
    ll x = a[i];
    for(int bit = 0; bit < 50; bit++) {
      if(1 & (x >> bit)) cnt[bit]++;
    }
  }
  memset(dp, -1 ,sizeof(dp));
  dp[50][0] = 0;
  for (int i = 49; i >= 0; i--) {
    ll p = (1LL << i);
    bool flag = false;
    if(1 & (k >> i)) flag = true;
    ll val0 = p * cnt[i]; // value when i-th bit is 0
    ll val1 = p * (n - cnt[i]);

    // 0: tight 1: loose
    // tight to tight
    if(dp[i + 1][0] != -1) {
      if(flag) dp[i][0] = max(dp[i][0] , dp[i + 1][0] + val1);
      else dp[i][0] = max(dp[i][0] , dp[i + 1][0] + val0);
    }
    // tight to loose
    if(dp[i + 1][0] != -1) {
      if(flag) dp[i][1] = max(dp[i][1] , dp[i + 1][0] + val0);
    }

    // loose to loose
    if(dp[i + 1][1] != -1) {
      dp[i][1] = max(dp[i][1], dp[i + 1][1] + val1);
      dp[i][1] = max(dp[i][1], dp[i + 1][1] + val0);
    }
  }
  cout << max(dp[0][0], dp[0][1]) << '\n';
}