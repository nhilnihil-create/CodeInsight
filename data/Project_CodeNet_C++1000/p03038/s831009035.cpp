#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<ll, ll>;

ll n, m;

int main() {
  cin >> n >> m;
  vector<ll> a(n);
  rep (i, n) {
    cin >> a[i];
  }
  vector<P> bc(m);
  rep (i, m) {
    cin >> bc[i].second >> bc[i].first;
  }
  sort(a.begin(), a.end());
  sort(bc.rbegin(), bc.rend());
  ll bcind = 0;
  rep (i, n) {
    if (a[i] >= bc[bcind].first) break;
    a[i] = bc[bcind].first;
    bc[bcind].second--;
    if (bc[bcind].second == 0) bcind++;
    if (bcind == m) break;
  }
  ll ans = 0;
  rep (i, n) {
    ans += a[i];
  }
  cout << ans << endl;
  return 0;
}
