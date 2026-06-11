#include <iostream>
#include <vector>
#define REP(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

ll n, h[200020], a[200020], dp[200020];
void update(int i, ll x) {
  for(; i <= n; i += i & -i) dp[i] = max(dp[i], x);
}
ll query(int i) {
  ll res = 0;
  for(; i > 0; i -= i & -i) res = max(res, dp[i]);
  return res;
}

int main()
{
  cin >> n;
  REP(i, n) cin >> h[i];
  REP(i, n) cin >> a[i];

  REP(i, n) update(h[i], query(h[i] - 1) + a[i]);

  cout << query(n);
  return 0;
}