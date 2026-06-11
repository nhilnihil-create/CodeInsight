#include <algorithm>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
#define fst first
#define snd second
using ll = long long;
using I = pair<int, int>;
const int D = 16;

// clang-format off
template <class T, size_t D> struct _Vec { using type = vector<typename _Vec<T, D - 1>::type>; };
template <class T> struct _Vec<T, 1> { using type = vector<T>; };
template <class T, size_t D> using Vec = typename _Vec<T, D>::type;
template <class T> vector<T> make_v(size_t size, const T& init) { return vector<T>(size, init); }
template <class... Ts> auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }
// clang-format on

vector<int> split(ll n) {
  vector<int> dig(D);
  for (int i = D - 1; i >= 0; i--) {
    dig[i] = n % 10;
    n /= 10;
  }
  return dig;
}

Vec<bool, 3> solveDP(const vector<int>& dig) {
  Vec<bool, 3> dp = make_v(D + 1, 2, D * 9 + 1, false);
  dp[D][0][0] = dp[D][1][0] = true;
  for (int i = D - 1; i >= 0; i--) {
    for (int big = 0; big < 2; big++) {
      for (int dsum = 0; dsum <= D * 9; dsum++) {
        for (int d = big ? 0 : dig[i]; d <= 9; d++) {
          if (dsum - d < 0) break;
          dp[i][big][dsum] =
              dp[i][big][dsum] | dp[i + 1][big | (d > dig[i])][dsum - d];
        }
      }
    }
  }
  return dp;
}

ll solveGreedy(const vector<int>& dig, const Vec<bool, 3>& dp, int dsum) {
  if (!dp[0][0][dsum]) {
    return -1;
  }
  ll m = 0;
  bool big = false;
  for (int i = 0; i < D; i++) {
    for (int d = big ? 0 : dig[i]; d <= 9; d++) {
      if (dp[i + 1][big | (d > dig[i])][dsum - d]) {
        m = m * 10 + d;
        big |= d > dig[i];
        dsum -= d;
        break;
      }
    }
  }
  return m;
}

ll f(ll n) {
  auto dig = split(n);
  auto dp = solveDP(dig);
  ll p = 1, q = 0;
  for (int k = 1; k <= D * 9; k++) {
    ll m = solveGreedy(dig, dp, k);
    if (m < 0) continue;
    if (p * k > m * q || (p * k == m * q && p > m)) {
      p = m;
      q = k;
    }
  }
  return p;
}

int main() {
  int K;
  while (cin >> K) {
    vector<ll> res;
    res.push_back(1);
    while (res.size() < K) {
      ll n = res.back();
      res.push_back(f(n + 1));
    }
    for (ll x : res) cout << x << endl;
  }
  return 0;
}
