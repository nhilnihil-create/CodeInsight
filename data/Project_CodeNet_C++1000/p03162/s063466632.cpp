#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep0(i, n) for (int i = 0; i <= (n); i++)
#define rep2(a, n) for (int i = a; i < (n); i++)
#define rep3(i, a, n) for (int i = a; i < (n); i++)
#define maxs(x, y) (x = max(x, y))
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
const int NUM = 100010;
int dp[NUM][3];

int main(void) {
  int n;
  cin >> n;
  rep(i, n) {
    vector<int> a(3);
    rep(i, 3) cin >> a[i];
    rep(j, 3) rep(k, 3) if (j != k) { maxs(dp[i + 1][j], dp[i][k] + a[j]); }
  }
  int ans = 0;
  rep(i, 3) maxs(ans, dp[n][i]);
  cout << ans << '\n';
  return 0;
}