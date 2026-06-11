#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
template <class T>
using vv = vector<vector<T>>;

#define in(v) \
  v;          \
  cin >> v;
// #define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
#define all(f, c, ...)                                 \
  (([&](decltype((c)) cccc) {                          \
    return (f)(begin(cccc), end(cccc), ##__VA_ARGS__); \
  })(c))
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) for (int i = 0, _i = (n); i < _i; ++i)
#define repi(i, a, b) for (int i = (a), _i = (b); i < _i; ++i)
#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)

#define rrep(i, n) for (int i = (n); i >= 0; --i)
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
template <class T>
bool chmax(T& a, const T& b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T& a, const T& b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}

// debug
template <class T>
ostream& operator<<(ostream& os, const vector<T>& vec) {
  os << "{";
  for (size_t i = 0; i < vec.size(); ++i) os << (i ? ", " : "") << vec[i];
  os << "}";
  return os;
}
ostream& operator<<(ostream& os, const vector<char>& v) {
  for (size_t i = 0; i < v.size(); ++i) os << v[i];
  return os;
}
template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& rhs) {
  os << "(" << rhs.first << ", " << rhs.second << ")";
  return os;
}

#ifdef LOCAL
void debug() { cerr << "\n"; }
template <class First>
void debug(const First& first) {
  cerr << first << "\n";
}
template <class First, class... Rest>
void debug(const First& first, const Rest&... rest) {
  cerr << first << ",";
  debug(rest...);
}
#else
#define debug(...) 42
#endif

int main() {
  int in(N);

  vi A(N);
  map<int, int> m;
  rep(i, N) {
    cin >> A[i];
    ++m[A[i]];
  }
  all(sort, A);

  int ans = 0;
  rrep(i, N - 1) {
    if (m[A[i]] == 0) continue;
    --m[A[i]];
    int pow = 1;
    while (2 * pow <= A[i]) pow *= 2;
    debug(A[i], 2 * pow);
    if (m[2 * pow - A[i]] > 0) {
      ++ans;
      --m[2 * pow - A[i]];
    }
  }
  cout << ans << endl;

  return 0;
}
