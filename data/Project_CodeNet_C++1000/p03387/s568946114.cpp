#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}
#ifdef __LOCAL
#define debug(x) cerr << __LINE__ << ": " << #x << " = " << x << endl
#define debugArray(x, n)                           \
  cerr << __LINE__ << ": " << #x << " = {";        \
  for (long long hoge = 0; (hoge) < (n); ++(hoge)) \
    cerr << ((hoge) ? "," : "") << x[hoge];        \
  cerr << "}" << endl
#else
#define debug(x) (void(0))
#define debugArray(x, n) (void(0))
#endif

template <typename T>
struct BinaryIndexedTree {
  vector<T> dat;
  BinaryIndexedTree(int n) : dat(n + 1, 0) {}
  BinaryIndexedTree(int n, T a) : BinaryIndexedTree(vector<T>(n, a)) {}
  BinaryIndexedTree(vector<T> y) : dat(y.size() + 1) {
    for (int i = 0; i < y.size(); ++i) dat[i + 1] = y[i];
    for (int i = 1; i + (i & -i) < dat.size(); ++i) dat[i + (i & -i)] += dat[i];
  }
  void add(int i, T a = 1) {
    for (++i; i < (int)dat.size(); i += i & -i) dat[i] += a;
  }
  T sum(int i) {  // sum [0,i)
    T s = 0;
    for (; i > 0; i &= i - 1) s += dat[i];
    return s;
  }
  // min { i : sum(i+1) > k } -> kth element(0-indexed)
  int find(T k) const {
    int i = 0;
    for (int p = 1 << (__lg(dat.size() - 1) + 1); p > 0; p >>= 1)
      if (i + p < (int)dat.size() && dat[i + p] <= k) k -= dat[i += p];
    return i + 1 == (int)dat.size() ? -1 : i;  // -1 -> no solutions
  }
};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int A, B, C;
  cin >> A >> B >> C;
  int X = max({A, B, C});
  if (((A + B + C) ^ X) & 1) X++;
  cout << (3 * X - (A + B + C)) / 2 << '\n';
  return 0;
}
