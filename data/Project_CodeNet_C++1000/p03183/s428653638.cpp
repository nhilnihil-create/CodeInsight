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

Blk A[1000];
long long F[1001][10001];

long long dfs(int n, int w) {
  if (n < 0)
    return 0;
  if (w > 10000)
    return 0;
  if (F[n][w] != -1)
    return F[n][w];
  F[n][w] = dfs(n - 1, w);
  if (w <= A[n].s)
    F[n][w] = max(F[n][w], dfs(n - 1, w + A[n].w) + A[n].v);
  return F[n][w];
}

int main() {
  int N;
  scanf("%d", &N);
  for (auto i = 0; i < N; ++i) {
    scanf("%d%d%d", &A[i].w, &A[i].s, &A[i].v);
    A[i].n = i;
  }
  sort(A, A + N, [](const Blk& a, const Blk& b) {
    return a.w + a.s != b.w + b.s ? a.w + a.s > b.w + b.s : a.n < b.n;
  });
  //static long long F[10001];
  //for (auto i = 0; i < N; ++i)
  //  for (auto j = A[i].w; j <= 10000; ++j)
  //    F[min(j - A[i].w, A[i].s)] = max(F[min(j - A[i].w, A[i].s)], F[j] + A[i].v);
  //static long long F[1001][10001];
  //for (auto i = 0; i < N; ++i)
  //  for (auto j = 0; j <= 10000; ++j) {
  //    F[i + 1][j] = max(F[i + 1][j], F[i][j]);
  //    if (j >= A[i].w)
  //      F[i + 1][min(j - A[i].w, A[i].s)] = max(F[i + 1][min(j - A[i].w, A[i].s)], F[i][j] + A[i].v);
  //  }
  memset(F, -1, sizeof(F));
  printf("%lld\n", dfs(N - 1, 0));
  return 0;
}
