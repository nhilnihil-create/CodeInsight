#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <numeric>
#include <functional>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <memory>
#include <thread>
#include <tuple>

using namespace std;

int main() {
  long long base = 0;
  int n, X;
  scanf("%d%d", &n, &X);
  /*n = 200000;
  X = 1000000000; */ 
  vector<int> x(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x[i]);
    //x[i] = 1000000000;
    base += X;
  }
  vector<long long> xsum(n + 1);
  for (int i = 0; i < n; i++) {
    xsum[i + 1] = xsum[i] + x[i];
  }
  long long ans = LLONG_MAX;
  for (int jump = 1; jump <= n; jump++) {
    long long level = 0;
    long long cur = base + (long long) jump * X;
    for (int k = n; k > 0; k -= jump) {
      int sind = max(0, k - jump);
      int eind = k;
      // [sind, eind)
      long long range = xsum[eind] - xsum[sind];

      long long prev = cur;

      if (level == 0) {
        cur += range * (1 + 4);
      }
      else {
        cur += range * (2 * level + 3);
      }

      if (prev > cur) {
        cur = LLONG_MAX;
        break;
      }
      level++;
    }
    ans = min(ans, cur);
  }
  printf("%lld\n", ans);
  return 0;
}
