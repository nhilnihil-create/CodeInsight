#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V< V<T> >;
template<class T> void assign(V<T>& v, int n, const T& a = T()) { v.assign(n, a); }
template<class T, class... U> void assign(V<T>& v, int n, const U&... u) { v.resize(n); for (auto&& i : v) assign(i, u...); }

struct M {
  using T = int;
  static T op(const T& a, const T& b) { return a + b; }
  static constexpr T e() { return 0; }
};

template<class M> struct ST {
  using T = typename M::T;
  int n;
  V<T> t;

  ST(int n) : n(n) {
    t.assign(2 * n, M::e());
  }

  void build() {
    for (int i = n - 1; i; i--) t[i] = M::op(t[2 * i], t[2 * i + 1]);
  }

  T get(int l, int r) {
    T resl = M::e(), resr = M::e();
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) { 
      if (l & 1) resl = M::op(resl, t[l++]); 
      if (r & 1) resr = M::op(t[--r], resr);
    }
    return M::op(resl, resr);
  }

  void set(int i, const T& a) {
    for (t[i += n] = a; i >>= 1;) t[i] = M::op(t[2 * i], t[2 * i + 1]);
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
    ST<M> st(2 * n + 1);
    for (int i = 0; i < n + 1; i++) {
      s += st.get(0, c[i] + 1);
      st.set(c[i], st.get(c[i], c[i] + 1) + 1);
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