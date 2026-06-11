#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for (ll i = 0; i < n; i++) cin >> a[i];

  using P = pair<ll, ll>;
  vector<P> vp;
  for (ll i = 0; i < m; i++) {
    ll b, c;
    cin >> b >> c;
    vp.emplace_back(c, b);
  }

  sort(a.begin(), a.end());
  sort(vp.begin(), vp.end());

  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    if (vp.empty() || vp.back().first <= a[i]) {
      ans += a[i];
      continue;
    }
    ans += vp.back().first;
    vp.back().second--;
    if (vp.back().second == 0) vp.pop_back();
  }
  cout << ans << endl;
  return 0;
}
