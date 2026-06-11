#include <bits/stdc++.h>
using namespace std;
#define rep(i, k, n) for(int i = (int)(k);i < (int)(n);i++)
int main() {
  int N;cin >> N;
  vector<int> dp(N), c(N);
  rep(i, 0, N) cin >> c[i];
  dp[0] = 0, dp[1] = abs(c[1]-c[0]);
  rep(i, 2, N) dp[i] = min(dp[i-1]+abs(c[i-1]-c[i]), dp[i-2]+abs(c[i-2]-c[i]));
  cout << dp[N-1] << endl;
}