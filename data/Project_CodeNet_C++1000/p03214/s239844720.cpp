#include <cstdio>
#include <cstdint>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <numeric>

int main() {
  size_t n;
  scanf("%zu", &n);

  std::vector<int> a(n);
  for (auto& ai: a) scanf("%d", &ai);

  int ns = n;
  int sum = std::accumulate(a.begin(), a.end(), 0);

  size_t res = 0;
  int diff = std::abs(sum - ns*a[0]);
  for (size_t i = 1; i < n; ++i) {
    int cur_diff = std::abs(sum - ns*a[i]);
    if (cur_diff < diff) {
      res = i;
      diff = cur_diff;
    }
  }
  printf("%zu\n", res);
}
