#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

template<class T> struct BIT {
  int n;
  V<T> t;

  BIT(int n) : n(n) {
    t.assign(n + 1, 0);
  }

  void add(int i, int a) {
    for (i++; i < n + 1; i += i & -i) t[i] += a;
  }

  T sum(int l, int r) {
    T res = 0;
    for (; r; r -= r & -r) res += t[r];
    for (; l; l -= l & -l) res -= t[l];
    return res;
  }
};

int main() {
  cin.tie(NULL); ios::sync_with_stdio(false);
  int n; cin >> n;
  V<> a(n); for (int i = 0; i < n; i++) cin >> a[i];
  auto chk = [&](int x) {
    V<> c(n + 1);
    c[0] = n;
    for (int i = 0; i < n; i++) c[i + 1] = c[i] + (a[i] >= x ? 1 : -1);
    lint s = 0;
    BIT<int> bit(2 * n + 1);
    for (int i = 0; i < n + 1; i++) {
      s += bit.sum(0, c[i] + 1);
      bit.add(c[i], 1);
    }
    return 4 * s >= (lint) n * (n + 1);
  };
  V<> b = a;
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  b.push_back(2e9);
  auto l = b.begin(), r = --b.end();
  while (r - l > 1) {
    auto m = l + (r - l) / 2;
    if (chk(*m)) l = m;
    else r = m;
  }
  cout << *l << '\n';
}