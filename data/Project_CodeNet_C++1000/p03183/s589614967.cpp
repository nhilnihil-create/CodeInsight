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

struct Blk {
  int w, s, v, n;
};

int main() {
  int N;
  scanf("%d", &N);
  static Blk A[1000];
  for (auto i = 0; i < N; ++i) {
    scanf("%d%d%d", &A[i].w, &A[i].s, &A[i].v);
    A[i].n = i;
  }
  sort(A, A + N, [](const Blk& a, const Blk& b) {
    return a.w + a.s != b.w + b.s ? a.w + a.s > b.w + b.s : a.n < b.n;
  });
  static long long F[10001];
  for (auto i = 0; i < N; ++i) {
    for (auto j = A[i].w; j <= 10000; ++j)
      F[min(j - A[i].w, A[i].s)] = max(F[min(j - A[i].w, A[i].s)], F[j] + A[i].v);
    for (auto j = 10001; j <= 10000 + A[i].w; ++j)
      F[min(j - A[i].w, A[i].s)] = max(F[min(j - A[i].w, A[i].s)], (long long) A[i].v);
  }
  printf("%lld\n", F[0]);
  return 0;
}
