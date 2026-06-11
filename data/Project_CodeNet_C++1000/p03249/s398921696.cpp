#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  if (n < 7) return cout << -1 << '\n', 0;
  V<lint> d(n); for (int i = 0; i < n; i++) cin >> d[i];
  map<lint, int> invd; for (int i = 0; i < n; i++) invd[d[i]] = i;
  set<lint> s; for (int i = 0; i < n; i++) s.insert(d[i]);
  VV<> g(n);
  V<> c(n, 1);
  while (!s.empty()) {
    int v = invd[*--s.end()];
    if (!s.count(d[v] - (n - 2 * c[v]))) break;
    int w = invd[d[v] - (n - 2 * c[v])];
    c[w] += c[v];
    g[v].push_back(w);
    g[w].push_back(v);
    s.erase(--s.end());
  }
  V<> d0(n, -1);
  queue<int> que;
  d0[0] = 0; que.push(0);
  while (!que.empty()) {
    int v = que.front(); que.pop();
    for (int w : g[v]) if (d0[w] == -1) {
      d0[w] = d0[v] + 1; que.push(w);
    }
  }
  for (int i = 0; i < n; i++) if (d0[i] == -1) return cout << -1 << '\n', 0;
  if (accumulate(d0.begin(), d0.end(), 0LL) != d[0]) return cout << -1 << '\n', 0;
  for (int v = 0; v < n; v++) for (int w : g[v]) if (v < w) cout << v + 1 << ' ' << w + 1 << '\n';
}