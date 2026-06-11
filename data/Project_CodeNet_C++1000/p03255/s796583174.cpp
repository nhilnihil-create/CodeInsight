#include <algorithm>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
using namespace std;
using ll = long long;
#define fst first
#define snd second

/* clang-format off */
template <class T, size_t D> struct _vec { using type = vector<typename _vec<T, D - 1>::type>; };
template <class T> struct _vec<T, 0> { using type = T; };
template <class T, size_t D> using vec = typename _vec<T, D>::type;
template <class T> vector<T> make_v(size_t size, const T& init) { return vector<T>(size, init); }
template <class... Ts> auto make_v(size_t size, Ts... rest) { return vector<decltype(make_v(rest...))>(size, make_v(rest...)); }
/* clang-format on */

int main() {
  int N;
  ll X;
  while (cin >> N >> X) {
    vector<ll> x(N);
    for (int i = 0; i < N; i++) cin >> x[i];
    auto f = [&](int K) {
      vector<ll> coef(N);
      for (int i = 0; i < K; i++) coef[i] = 5;
      for (int i = K; i < N; i++) coef[i] = 2 * ((i - K) / K + 2) + 1;
      ll cost = (N + K) * X;
      for (int i = 0; i < N; i++) cost += coef[N - i - 1] * x[i];
      return cost;
    };
    int l = 1, r = N;
    while (r - l > 10) {
      int s = (r - l) / 3;
      int a = l + s;
      int b = r - s;
      if (f(a) > f(b)) {
        l = a;
      } else {
        r = b;
      }
    }
    ll res = 1ll << 60;
    for (int k = max(1, r - 10); k <= min(N, r + 10); k++) {
      res = min(res, f(k));
    }
    cout << res << endl;
  }
  return 0;
}
