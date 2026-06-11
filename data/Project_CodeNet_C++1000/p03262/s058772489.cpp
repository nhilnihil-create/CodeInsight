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
template <class INT_T>
INT_T gcd(INT_T a, INT_T b) {
  if(a < b) return gcd(b, a);
  INT_T r;
  while ((r=a%b)) { a = b; b = r; }
  return b;
}
// template <class INT_T>
// INT_T ___gcd(INT_T a, INT_T b){
//     if(a<b) swap(a,b);
//     if(a%b==0) return b;
//     return ___gcd(a%b,b);
// }
// template <class INT_T>
// INT_T lcm(INT_T a, INT_T b){
//     return a/___gcd(a,b)*b;
// }
//

void solve(long long N, long long X, std::vector<long long> x) {
  rep(i,N) { x[i] -= X; x[i] = abs(x[i]); }
  //dump(x);
  // xの最大公約数を求めればOK
  ll D = x[0];
  rep(i,1,N){
    D = gcd(D,x[i]);
  }
  cout << D << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false); // Magic for faster cin
  cout.precision(12);
  long long N;
  std::cin >> N;
  long long X;
  std::cin >> X;
  std::vector<long long> x(N);
  for (int i = 0; i < N; i++) {
    std::cin >> x[i];
  }
  solve(N, X, std::move(x));
  return 0;
}
