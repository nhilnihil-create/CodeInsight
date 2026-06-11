#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int n;
  scanf("%d", &n);
  vector<tuple<int, int, int, int>> block;
  block.reserve(n);
  int m = 0;
  while (n--) {
    int w, s, v;
    scanf("%d%d%d", &w, &s, &v);
    m = max(m, w + s);
    block.emplace_back(w + s, w, s, v);
  }
  sort(block.begin(), block.end());
  vector<ll> dp(m + 1);
  for (const auto& tup : block) {
    int key, w, s, v;
    tie(key, w, s, v) = tup;
    for (int i = s; i >= 0; --i)
      dp[i + w] = max(dp[i + w], dp[i] + v);
  }
  printf("%lld\n", *max_element(dp.begin(), dp.end()));

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
