#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
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

using P = pair<int, int>;

int main() {
  int H, W, N;
  while (cin >> H >> W >> N) {
    map<int, int> leftMostHole;
    for (int i = 0; i < N; i++) {
      int y, x;
      cin >> y >> x;
      --y;
      --x;
      if (y == 0) continue;
      if (leftMostHole.count(y)) {
        leftMostHole[y] = min(leftMostHole[y], x);
      } else {
        leftMostHole[y] = x;
      }
    }
    leftMostHole[H] = 0;
    int res;
    int wide = 1, preY = 0;
    for (auto& ps : leftMostHole) {
      int y = ps.fst;
      int x = ps.snd;
      wide = min(wide + y - preY - 1, W);
      if (x < wide) {
        res = y;
        break;
      }
      wide = min(wide + 1, x);
      preY = y;
    }
    cout << res << endl;
  }
  return 0;
}
