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
  double X;
  while (cin >> N >> X) {
    vector<double> x(N);
    for (int i = 0; i < N; i++) cin >> x[i];
    reverse(x.begin(), x.end());
    vector<double> sum(N + 1);
    sum[0] = 0;
    for (int i = 0; i < N; i++) sum[i + 1] = sum[i] + x[i];
    double res = 1ll << 60;
    for (int K = 1; K <= N; K++) {
      double cost = (N + K) * X;
      cost += sum[K] * 5;
      for (int i = K; i < N; i += K) {
        double coef = 2 * ((i - K) / K + 2) + 1;
        cost += coef * (sum[min(N, i + K)] - sum[i]);
      }
      res = min(res, cost);
    }
    cout << (ll)res << endl;
  }
  return 0;
}
