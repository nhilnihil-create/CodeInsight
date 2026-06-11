#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m), c(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i] >> c[i];

  vector<P> ps(m);
  rep(i, m) ps[i] = make_pair(-c[i], b[i]);
  sort(ps.begin(), ps.end());
  rep(i, m) {
    rep(j, ps[i].second) a.push_back(-ps[i].first);
    if (a.size() >= 2 * n) break;
  }
  sort(a.begin(), a.end(), greater<int>());
  ll ans = 0;
  rep(i, n) ans += a[i];
  cout << ans << endl;
  return 0;
}