#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define erep(i, n) for (ll i = 1; i <= (n)i++)
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
// input
ll h[100010];
// dp tabel
ll dp[100010];

int main(void) {
  ll n;
  cin >> n;
  rep(i, n) cin >> h[i];
  rep(i, 100010) dp[i] = 1e9;
  dp[0] = 0;
  rep(i, n) {
    mins(dp[i + 1], dp[i] + abs(h[i + 1] - h[i]));
    mins(dp[i + 2], dp[i] + abs(h[i + 2] - h[i]));
  }
  cout << dp[n - 1] << '\n';
  return 0;
}