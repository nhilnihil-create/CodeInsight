#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep0(i, n) for (int i = 0; i <= (n); i++)
#define rep2(a, n) for (int i = a; i < (n); i++)
#define rep3(i, a, n) for (int i = a; i < (n); i++)
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
// dp
ll dp[100010];
// input
ll h[100010];

int main(void) {
  int n, k;
  cin >> n >> k;
  rep(i, n) cin >> h[i];
  rep(i, 100010) dp[i] = INF;
  dp[0] = 0;
  rep(i, n) rep0(j, k) {
    dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
  }
  cout << dp[n - 1] << '\n';
  return 0;
}