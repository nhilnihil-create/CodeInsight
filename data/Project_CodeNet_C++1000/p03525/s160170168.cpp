#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> d, conf, unconf;

int solve();

int main() {
  cin >> n;
  d.resize(n);
  for (auto& p : d) cin >> p;
  sort(d.begin(), d.end());
  cout << solve() << endl;
  return 0;
}

int solve() {
  int res = 0;
  if (!d[0]) return 0;
  conf.push_back(0);
  for (int i = 0; i < n;) {
    int cnt = 0, now = d[i];
    while (i < n && now == d[i]) ++i, ++cnt;
    if (cnt > 2) return 0;
    if (cnt == 2) {
      conf.push_back(now);
      conf.push_back(24 - now);
    } else
      unconf.push_back(now);
  }
  int len = unconf.size();
  for (int i = 0; i < (1 << len); ++i) {
    vector<int> v = conf;
    for (int j = 0; j < len; ++j)
      if (i >> j & 1)
        v.push_back(unconf[j]);
      else
        v.push_back(24 - unconf[j]);
    sort(v.begin(), v.end());
    int now = 24;
    for (int j = 0; j <= n + 1; ++j)
      now = min({now, abs(v[j] - v[(j + 1) % (n + 1)]),
                 24 - abs(v[j] - v[(j + 1) % (n + 1)])});
    res = max(res, now);
  }
  return res;
}