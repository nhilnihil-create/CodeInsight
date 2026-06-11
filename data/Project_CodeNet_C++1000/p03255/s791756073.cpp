#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  lint n, c; cin >> n >> c;
  V<lint> x(n); for (int i = 0; i < n; i++) cin >> x[i];
  V<lint> cx(n + 1); for (int i = 0; i < n; i++) cx[i + 1] = cx[i] + x[i];
  lint res = 9e18, th;
  for (lint i = n; i; i--) {
    lint tmp = (n + i) * c;
    lint j = 0;
    while (true) {
      tmp += (cx[n - j * i] - cx[max(n - (j + 1) * i, 0LL)]) * max(2 * j + 3, 5LL);
      j++;
      if (n- j * i < 0) break;
    }
    if (i == n) th = tmp;
    if (tmp > th) break;
    res = min(res, tmp);
  }
  cout << res << '\n';
}