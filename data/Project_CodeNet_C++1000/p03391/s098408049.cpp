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
  V<> a(n), b(n); for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
  lint res = accumulate(a.begin(), a.end(), 0LL);
  lint t = res;
  for (int i = 0; i < n; i++) if (a[i] > b[i]) t = min(t, (lint) b[i]);
  res -= t;
  cout << res << '\n';
}