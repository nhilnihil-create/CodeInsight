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
  V<> x(n), y(n); for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
  for (int i = 0; i < n; i++) if (x[0] + y[0] + x[i] + y[i] & 1) return cout << -1 << '\n', 0;
  V<> d;
  V<string> w(n);
  if (~(x[0] + y[0]) & 1) {
    d.push_back(1);
    for (int i = 0; i < n; i++) {
      x[i]--;
      w[i].push_back('R');
    }
  }
  for (int l = 1 << 30; l; l >>= 1) {
    d.push_back(l);
    for (int i = 0; i < n; i++) {
      if (x[i] + y[i] > 0) {
        if (x[i] - y[i] > 0) {
          x[i] -= l;
          w[i].push_back('R');
        } else {
          y[i] -= l;
          w[i].push_back('U');
        }
      } else {
        if (x[i] - y[i] > 0) {
          y[i] += l;
          w[i].push_back('D');
        } else {
          x[i] += l;
          w[i].push_back('L');
        }
      }
    }
  }
  int m = d.size();
  cout << m << '\n';
  for (int i = 0; i < m; i++) cout << d[i] << (i != m - 1 ? ' ' : '\n');
  for (int i = 0; i < n; i++) cout << w[i] << '\n';
}