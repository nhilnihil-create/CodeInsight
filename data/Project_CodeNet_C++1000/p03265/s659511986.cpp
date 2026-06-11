#include <bits/stdc++.h>
using namespace std;

// Loops
#define _overload3(_1, _2, _3, name, ...) name
#define _rep(i, n) repi(i, 0, n)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define _rrep(i, n) rrepi(i, n, 0)
#define rrepi(i, a, b) for (int i = int(a) - 1; i >= int(b); --i)

#define rep(...) _overload3(__VA_ARGS__, repi, _rep, )(__VA_ARGS__)
#define rrep(...) _overload3(__VA_ARGS__, rrepi, _rrep, )(__VA_ARGS__)
#define each(xi, x) for (auto &&xi : x)
// Note: we can use rep(i,N) or rep(i,from,to)

// typedef
template <class T> using vec = vector<T>;
using ll = long long;
using vi = vec<ll>;
using vvi = vec<vi>;
using vvvi = vec<vvi>;
using pii = pair<ll, ll>;

// Constants

// Shorter repr for frequently used terms
#define pb push_back
#define mp make_pair

// Algorithms
#define all(x) (x).begin(), (x).end()
#define uniq(v) v.erase(unique(all(v)), v.end())
#define perm(c)                                                                \
  sort(all(c));                                                                \
  for (bool c##p = 1; c##p; c##p = next_permutation(all(c)))

template <class T> pair<T, size_t> max(vector<T> &x) {
  auto it = max_element(all(x));
  return mp(*it, it - x.begin());
}
template <class T> pair<T, size_t> min(vector<T> &x) {
  auto it = min_element(all(x));
  return mp(*it, it - x.begin());
}

template <class T> inline bool chmax(T &maxval, const T &newval) {
  if (maxval < newval) {
    maxval = newval;
    return 1;
  }
  return 0;
}
template <class T> inline bool chmin(T &minval, const T &newval) {
  if (minval > newval) {
    minval = newval;
    return 1;
  }
  return 0;
}

// Utilities
// Grid world utilities
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
#define inside(H, W, y, x) 0 <= (x) && (x) < (W) && 0 <= (y) && (y) < (H)

// Debug
#ifdef LOCAL
#include "dump.hpp"
#define debug(x) cerr << #x << ": " << x << '\n'
#else
#define dump(...)
#define debug(x)
#endif

// Yes or No
void yesno(bool ok, string yes = "Yes", string no = "No") {
  cout << (ok ? yes : no) << endl;
}

// Paste snippets here!!

//

pair<ll,ll> rotate(pair<ll,ll> x){
  // ベクトルを時計回りに90度回転する
  return mp(x.second, -x.first);
}

void solve(std::vector<long long> x, std::vector<long long> y) {
  ll x1, x2, y1, y2;
  x1 = x[0]; x2 = x[1];
  y1 = y[0]; y2 = y[1];
  ll ippen = max(abs(x[0]-x[1]), abs(y[0]-y[1]));
  pair<ll,ll> v = mp(x[0]-x[1], y[0]-y[1]);
  ll x3, x4, y3, y4;

  v = rotate(v);
  x3 = x2 + v.first;
  y3 = y2 + v.second;

  v = mp(x2-x3, y2-y3);
  v = rotate(v);
  x4 = x3 + v.first;
  y4 = y3 + v.second;
  
  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false); // Magic for faster cin
  cout.precision(12);
  std::vector<long long> x(2);
  std::vector<long long> y(2);
  for (int i = 0; i < 2; i++) {
    std::cin >> x[i];
    std::cin >> y[i];
  }
  solve(std::move(x), std::move(y));
  return 0;
}
