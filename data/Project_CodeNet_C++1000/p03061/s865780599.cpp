#include <bits/stdc++.h>
using namespace std;

template<typename T, typename U> void cmax(T &a, U b) { if (a < b) a = b; }
template<typename T, typename U> void cmin(T &a, U b) { if (a > b) a = b; }

template <class S, S (*op)(S, S), S (*el)()> class SegmentTree {
private:
  int N, size, log;
  vector<S> D;
  void apply(int k) { D.at(k) = op(D.at(2 * k), D.at(2 * k + 1)); }
  int ceil_pow(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
  }

public:
  SegmentTree() : SegmentTree(0) {}
  SegmentTree(int n) : SegmentTree(vector<S>(n, el())) {}
  SegmentTree(const vector<S>& v) : N(int(v.size())) {
    log = ceil_pow(N);
    size = 1 << log;
    D = vector<S>(2 * size, el());
    for (int i = 0; i < N; i++) D.at(size + i) = v.at(i);
    for (int i = size - 1; i >= 1; i--) {
      apply(i);
    }
  }
  void set(int p, S x) {
    p += size;
    D.at(p) = x;
    for (int i = 1; i <= log; i++) apply(p >> i);
  }
  S get(int p) { return D.at(p + size); }
  S query(int l, int r) {
    r++;
    S sml = el(), smr = el();
    l += size, r += size;
    while (l < r) {
      if (l & 1) sml = op(sml, D.at(l++));
      if (r & 1) smr = op(D.at(--r), smr);
      l >>= 1, r >>= 1;
    }
    return op(sml, smr);
  }
  S query_all() { return D.at(1); }
  template <bool (*f)(S)> int max_right(int l) {
    return max_right(l, [](S x) { return f(x); });
  }
  template <class F> int max_right(int l, F f) {
    if (l == N) return N;
    l += size;
    S sm = el();
    do {
      while (l % 2 == 0) l >>= 1;
      if (!f(op(sm, D.at(l)))) {
        while (l < size) {
          l = (2 * l);
          if (f(op(sm, D.at(l)))) sm = op(sm, D.at(l++));
        }
        return l - size;
      }
      sm = op(sm, D.at(l++));
    } while ((l & -l) != l);
    return N;
  }
  template <bool (*f)(S)> int min_left(int r) {
    return min_left(r, [](S x) { return f(x); });
  }
  template <class F> int min_left(int r, F f) {
    if (r == 0) return 0;
    r += size;
    S sm = el();
    do {
      r--;
      while (r > 1 && (r % 2)) r >>= 1;
      if (!f(op(D.at(r), sm))) {
        while (r < size) {
          r = (2 * r + 1);
          if (f(op(D.at(r), sm))) sm = op(D.at(r--), sm);
        }
        return r + 1 - size;
      }
      sm = op(D.at(r), sm);
    } while ((r & -r) != r);
    return 0;
  }
};

int op(int a, int b) { return gcd(a, b); };
int el() { return 0; };

signed main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  SegmentTree<int, op, el> ST(A);

  int ans = 1;
  cmax(ans, ST.query(1, N - 1));
  for (int i = 1; i + 1 < N; i++) {
    cmax(ans, gcd(ST.query(0, i - 1), ST.query(i + 1, N - 1)));
  }
  cmax(ans, ST.query(0, N - 2));
  cout << ans << "\n";
}