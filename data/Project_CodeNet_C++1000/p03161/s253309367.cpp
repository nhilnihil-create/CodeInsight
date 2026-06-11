#include <bits/stdc++.h>
using namespace std;
#define rep(i, k, n) for(int i = (int)(k);i < (int)(n);i++)
int main() {
  int N, K;cin >> N >> K;
  vector<int> dp(100005), c(N);
  rep(i, 0, N) cin >> c[i];
  dp[0] = 0;
  rep(i, 1, K) dp[i] = abs(c[0] - c[i]);
  rep(i, K, N) {
    dp[i] = dp[i-1]+abs(c[i-1]-c[i]);
    rep(j, 1, K) dp[i] = min(dp[i], dp[i-j-1]+abs(c[i-j-1]-c[i]));
  }
  cout << dp[N-1] << endl;
}