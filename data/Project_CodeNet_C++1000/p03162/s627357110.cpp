#include <bits/stdc++.h>
using namespace std;
#define rep(i, k, n) for(int i = (int)(k);i < (int)(n);i++)
int main() {
  int N;cin >> N;
  vector<vector<int>> dp(N+1, vector<int>(3, 0));
  vector<int> a(N), b(N), c(N);
  rep(i, 1, N+1) cin >> a[i] >> b[i] >> c[i];
  rep(i, 1, N+1) {
    dp[i][0] = max(dp[i-1][1] + a[i], dp[i-1][2] + a[i]);
    dp[i][1] = max(dp[i-1][2] + b[i], dp[i-1][0] + b[i]);
    dp[i][2] = max(dp[i-1][0] + c[i], dp[i-1][1] + c[i]);
  }
  cout << max(dp[N][0], max(dp[N][1], dp[N][2])) << endl;
}