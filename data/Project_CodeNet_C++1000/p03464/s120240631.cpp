#include <bits/stdc++.h>
#include <type_traits>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define ddrep(i, n) for (int i = n; i > 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define ssrep(i, s, t) for (int i = s; i <= t; ++i)

#define rng(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

#define chmax(x, y) (x = max(x, y))
#define chmin(x, y) (x = min(x, y))

using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using ld = long double;

template <class T, class U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &v) {
  os << "{";
  rep(i, (int)v.size()) {
    if (i)
      os << ",";
    os << v[i];
  }
  os << "}";
  return os;
}

template <typename T, size_t S> void printArray(const T (&array)[S]) {
  for (auto val : array)
    std::cout << val << ", ";
  std::cout << "\n";
}

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int gcd(int x, int y) {
  if (y == 0) return x;
  return gcd(y, x%y);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << std::setprecision(10);

  int k; std::cin >> k;
  vector<ll> a(k); rep(i, k) std::cin >> a[i];
  bool ok = true;
  if (a[k-1] != 2) ok = false;
  ll mi = 2, ma = 3;
  drep(i, k-1) {
    if (ma < a[i] || (ma / a[i]) * a[i] < mi) ok = false;
    if (mi % a[i]) mi += a[i] - mi % a[i];
    ma = (ma / a[i]) * a[i] + a[i]-1;
  }
  if (ok)
    std::cout << mi << " " << ma << "\n";
  else
    std::cout << -1 << "\n";
}
