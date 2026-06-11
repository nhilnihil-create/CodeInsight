#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 1e9;

int main() {
  int n;
  cin >> n;
  vector<int> dp(n+1, INF);
  dp[0] = 0;
  rep(i, n) {
    dp[i+1] = min(dp[i+1], dp[i] + 1);
    for (int j = 6; i+j <= n; j *= 6) {
      dp[i+j] = min(dp[i+j], dp[i] + 1);
    }
    for (int j = 9; i+j <= n; j *= 9) {
      dp[i+j] = min(dp[i+j], dp[i] + 1);
    }
  }
  cout << dp[n] << endl;
  return 0;
}