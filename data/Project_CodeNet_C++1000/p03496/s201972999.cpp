#include <bits/stdc++.h>
#define REP(i, a, n) for (int i = (a); i < (int)(n); ++i)
#define REPC(i, a, n) for (int i = (a); i <= (int)(n); ++i)
#define ALL(t) t.begin(), t.end()
#define RALL(t) t.rbegin(), t.rend()
#define MATINIT(type, row, col, init) \
  vector<vector<type>>(row, vector<type>(col, init));
#define Yes(cond) cout << (cond ? "Yes" : "No") << endl;
#define YES(cond) cout << (cond ? "YES" : "NO") << endl;
using namespace std;
using LL = long long;
using ULL = unsigned long long;
template <class T>
using VEC = std::vector<T>;
template <class T>
using MAT = std::vector<std::vector<T>>;
void DUMP() { cerr << endl; }
template <class Head, class... Tail>
void DUMP(Head &&head, Tail &&... tail) {
  cerr << head << ", ";
  DUMP(std::move(tail)...);
}
template <typename T>
ostream &operator<<(ostream &os, vector<T> &vec) {
  os << "{";
  for (auto v : vec) os << v << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, map<T1, T2> &m) {
  os << "{";
  for (auto p : m) os << p << ",";
  os << "}";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
  os << "[" << p.first << " " << p.second << "]";
  return os;
}

int main() {
  int n;
  cin >> n;
  VEC<LL> a(n);
  LL mii = 0;
  LL mai = 0;
  REP(i, 0, n) {
    cin >> a[i];
    if (a[i] < a[mii]) mii = i;
    if (a[i] > a[mai]) mai = i;
  }
  int init = abs(a[mii]) > abs(a[mai]) ? mii : mai;
  cout << 2 * n-1 << endl;
  if (a[init] >= 0) {
    REP(i, 0, n) { cout << init + 1 << " " << i + 1 << endl; }
    REP(i, 0, n-1) { cout << i + 1 << " " << i + 2 << endl; }
  }
  if (a[init] < 0) {
    REP(i, 0, n) { cout << init + 1 << " " << i + 1 << endl; }
    for (int i = n - 2; i >= 0; --i) {
      cout << i + 2 << " " << i + 1 << endl;
    }
  }

  return 0;
}
