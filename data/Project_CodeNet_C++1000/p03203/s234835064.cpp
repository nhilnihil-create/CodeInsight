#include <bits/stdc++.h>
using namespace std;

using P = pair<long long, long long>;

long long n, h, w;
vector<P> v;

long long solve();

int main() {
  cin >> h >> w >> n;
  v.resize(n);
  for (auto &p : v) {
    cin >> p.second >> p.first;
    --p.first, --p.second;
  }
  for (int i = 0; i < w; ++i) v.emplace_back(i, h);
  n = v.size();
  sort(v.begin(), v.end());
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long res = 1e10, x = 0;
  for (int i = 0, id = 0; i < w && x < h; ++i) {
    while (id < n && v[id].first == i) res = min(res, v[id++].second);
    while (id < n && v[id].first == i + 1 && x + 1 >= v[id].second)
      if (x + 1 == v[id++].second) ++x;
    ++x;
  }
  return res;
}