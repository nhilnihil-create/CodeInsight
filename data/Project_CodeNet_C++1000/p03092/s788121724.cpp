#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

typedef long long lint;

const int maxn = 5000;

int main() {
  int n;
  int right_cost, left_cost;
  scanf("%d %d %d", &n, &right_cost, &left_cost);
  vector<int> perm(n), invperm(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &perm[i]), --perm[i];
    invperm[perm[i]] = i;
  }

  vector<lint> prev_dp(n + 1);
  vector<lint> dp(n + 1, 0LL);
  for (int v = n - 1; v >= 0; --v) {
    swap(dp, prev_dp);

    int my_pos = invperm[v];
    int bigger_before = 0;
    for (int i = 0; i < my_pos; ++i)
      if (perm[i] > v)
        ++bigger_before;

    for (int i = 0; i <= n; ++i) {
      lint &res = dp[i];

      if (my_pos < i) {
        res = prev_dp[i];
      } else if (bigger_before == 0) {
        res = prev_dp[my_pos + 1];
      } else {
        res = min((lint)bigger_before * right_cost + prev_dp[my_pos + 1],
                  left_cost + prev_dp[i]);
      }

      if (0 <= i && i < my_pos && perm[i] > v)
        --bigger_before;
    }
  }

  printf("%lld\n", dp[0]);

  return 0;
}
