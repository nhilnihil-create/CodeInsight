#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
#define REP(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

ll n, m, h[200020], a[200020];
vector<ll> dp;
void update(int i, ll x) {
  i += m - 1;
  dp[i] = max(dp[i], x);
  while (i > 0) {
    i = (i - 1) >> 1;
    dp[i] = max(dp[i * 2 + 1], dp[i * 2 + 2]);
  }
}
ll query(int a, int b, int l, int r, int i) {
  if (b <= l || r <= a) return 0;
  if (a <= l && r <= b) return dp[i];
  ll v1 = query(a, b, l, (l + r) >> 1, i * 2 + 1);
  ll v2 = query(a, b, (l + r) >> 1, r, i * 2 + 2);
  return max(v1, v2);
}

int main()
{
  cin >> n;
  REP(i, n) cin >> h[i];
  REP(i, n) cin >> a[i];
  // init
  for(m = 1; m < n; m <<= 1);
  dp.resize(m * 2 - 1);

  REP(i, n) {
    ll mx = query(0, h[i], 0, m, 0) + a[i];
    update(h[i] - 1, mx);
  }

  cout << query(0, m, 0, m, 0);
  return 0;
}