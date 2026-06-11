#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using VI = vector<ll>;
using VVI = vector<VI>;

void compress(VI &v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
}

ll idx(VI &v, ll i) { return lower_bound(v.begin(), v.end(), i) - v.begin(); }

int main() {
  ll n, m;
  cin >> n >> m;
  VI p(m), ps(m), y(m), ys(m);

  for (int i = 0; i < m; i++) {
    cin >> p[i] >> y[i];
    ps[i] = p[i];
    ys[i] = y[i];
  }

  compress(ps);
  compress(ys);
  VVI tbl = VVI(ps.size() + 1);

  for (int i = 0; i < m; i++) {
    ll tp = idx(ps, p[i]);  // [ps.begin, ps.end] <=> 0〜ps.size()
    tbl[tp].push_back(y[i]);
  }
  for (auto &&pp : ps) {
    ll tp = idx(ps, pp);
    sort(tbl[tp].begin(), tbl[tp].end());
  }

  for (int i = 0; i < m; i++) {
    ll tp = idx(ps, p[i]);
    auto itr = lower_bound(tbl[tp].begin(), tbl[tp].end(), y[i]);
    ll ty = (itr - tbl[tp].begin()) + 1;
    printf("%06lld%06lld\n", p[i], ty);
  }
  return 0;
}
