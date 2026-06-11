#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define rep(i, n) REP(i, 0, n)

int main() {
  ll x, y, z, k;
  cin >> x >> y >> z >> k;
  vector<ll> a(x), b(y), c(z);
  rep(i, x) cin >> a[i];
  rep(i, y) cin >> b[i];
  rep(i, z) cin >> c[i];
  vector<ll> cur;
  rep(i, x) rep(j, y) { cur.push_back(a[i] + b[j]); }
  sort(cur.begin(), cur.end(), greater<>());
  if (cur.size() > k) cur.resize(k);
  vector<ll> res;
  rep(i, cur.size()) rep(j, z) { res.push_back(cur[i] + c[j]); }
  sort(res.begin(), res.end(), greater<>());
  rep(i, k) { cout << res[i] << endl; }
  return 0;
}
