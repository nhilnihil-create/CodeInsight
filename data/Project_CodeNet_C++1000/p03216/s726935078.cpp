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

int main() {
  int N, Q;
  string S;
  while (cin >> N >> S >> Q) {
    vector<ll> sumD(N + 1, 0), sumM(N + 1, 0), sumPair(N + 1, 0);
    for (int i = 0; i < N; i++) {
      sumD[i + 1] = sumD[i] + (S[i] == 'D');
      sumM[i + 1] = sumM[i] + (S[i] == 'M');
      sumPair[i + 1] = sumPair[i];
      if (S[i] == 'M') {
        sumPair[i + 1] += sumD[i];
      }
    }
    for (int q = 0; q < Q; q++) {
      int k;
      cin >> k;
      ll res = 0;
      for (int i = 0; i < N; i++) {
        if (S[i] == 'C') {
          int j = max(0, i - (k - 1));
          ll ways = (sumPair[i] - sumPair[j]) - (sumM[i] - sumM[j]) * sumD[j];
          res += ways;
        }
      }
      cout << res << endl;
    }
  }
  return 0;
}
