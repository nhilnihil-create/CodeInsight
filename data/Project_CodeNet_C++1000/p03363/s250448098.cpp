#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> cum(n+1);
  cum[0] = 0;
  rep(i, n) cum[i+1] = cum[i] + a[i];
  sort(cum.begin(), cum.end());

  ll ans = 0;
  ll now = cum[0];
  while (1) {
    int ib = lower_bound(cum.begin(), cum.end(), now) - cum.begin();
    int ie = upper_bound(cum.begin(), cum.end(), now) - cum.begin();
    ans += (ll)(ie - ib) * (ie - ib - 1) / 2;
    if (ie == cum.size()) break;
    now = cum[ie];
  }
  cout << ans << endl;
  return 0;
}