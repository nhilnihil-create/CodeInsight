#include <algorithm>
#include <bitset>
#include <cassert>
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
template <class T> inline void chmin(T &a, const T& b) { if (b < a) a = b; }
template <class T> inline void chmax(T &a, const T& b) { if (b > a) a = b; }
/* clang-format on */

int main() {
#ifdef DEBUG
  ifstream cin("in.txt");
#endif
  int N, Q;
  while (cin >> N >> Q) {
    string S;
    cin >> S;
    vector<char> T(Q), D(Q);
    for (int q = 0; q < Q; q++) cin >> T[q] >> D[q];
    auto simulate = [&](int i, int edge) {
      for (int q = 0; q < Q; q++) {
        if (S[i] == T[q]) {
          i += D[q] == 'L' ? -1 : +1;
        }
        if (i < 0 || i >= N) return i == edge;
      }
      return false;
    };
    auto bsearch = [&](int edge, int pass, int fail) {
      while (abs(pass - fail) > 1) {
        int i = (pass + fail) / 2;
        if (simulate(i, edge)) {
          pass = i;
        } else {
          fail = i;
        }
      }
      return pass;
    };
    int res = N;
    res -= bsearch(-1, -1, N) + 1;
    res -= N - bsearch(N, N, -1);
    cout << res << endl;
  }
  return 0;
}
