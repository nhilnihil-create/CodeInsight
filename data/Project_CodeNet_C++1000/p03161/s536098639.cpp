#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  rep(i, n) cin >> h[i];

  vector<ll> dp(n, 1e12);
  dp[0] = 0;
  rep(i, n) rep(j, k) {
    if (i+j+1 < n) dp[i+j+1] = min(dp[i+j+1], dp[i] + abs(h[i] - h[i+j+1]));
  }
  cout << dp[n-1] << endl;
  return 0;
}