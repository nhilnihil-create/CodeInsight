#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <complex>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;

int main() {
  int N;
  scanf("%d", &N);
  static int A[16][16];
  for (auto i = 0; i < N; ++i)
    for (auto j = 0; j < N; ++j)
      scanf("%d", &A[i][j]);
  auto mask = (1u << N) - 1;
  static long long F[1 << 16];
  static int T[16];
  for (auto s = 1u; s <= mask; ++s) {
    auto c = 0;
    for (auto t = s; t; ) {
      auto u = t & -t;
      t ^= u;
      T[c++] = __builtin_ctz(u);
    }
    for (auto i = 1; i < c; ++i)
      for (auto j = 0; j < i; ++j)
        F[s] += A[T[i]][T[j]];
  }
  for (auto s = 1u; s <= mask; ++s)
    for (auto t = (s - 1) & s; t; t = (t - 1) & s)
      F[s] = max(F[s], F[t] + F[s ^ t]);
  printf("%lld\n", F[mask]);
  return 0;
}
