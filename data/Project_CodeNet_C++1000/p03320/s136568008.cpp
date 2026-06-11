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

template <class T, int D>
class Vec {
  using V = Vec<T, D - 1>;
  vector<V> vec;

 public:
  template <class... I>
  Vec(int size, I... rest) : vec(size, V(rest...)) {}
  int size() const { return vec.size(); }
  V& operator[](int i) { return vec[i]; }
  const V& operator[](int i) const { return vec[i]; }
};

template <class T>
class Vec<T, 1> {
  vector<T> vec;

 public:
  Vec(int size) : vec(size) {}
  Vec(int size, const T& init) : vec(size, init) {}
  T& operator[](int i) { return vec[i]; }
  const T& operator[](int i) const { return vec[i]; }
};

vector<int> split(ll n) {
  vector<int> dig(D);
  for (int i = D - 1; i >= 0; i--) {
    dig[i] = n % 10;
    n /= 10;
  }
  return dig;
}

Vec<int, 3> solveDP(const vector<int>& dig) {
  Vec<int, 3> dp(D + 1, 2, D * 9 + 1, 0);
  dp[D][0][0] = dp[D][1][0] = 1;
  for (int i = D - 1; i >= 0; i--) {
    for (int big = 0; big < 2; big++) {
      for (int dsum = 0; dsum <= D * 9; dsum++) {
        for (int d = big ? 0 : dig[i]; d <= 9; d++) {
          if (dsum - d < 0) break;
          dp[i][big][dsum] |= dp[i + 1][big | (d > dig[i])][dsum - d];
        }
      }
    }
  }
  return dp;
}

ll solveGreedy(const vector<int>& dig, const Vec<int, 3>& dp, int dsum) {
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
