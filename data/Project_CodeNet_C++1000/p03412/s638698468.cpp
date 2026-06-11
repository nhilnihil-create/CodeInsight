#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>

int main() {
  size_t n;
  scanf("%zu", &n);

  std::vector<intmax_t> a(n), b(n);
  for (auto& ai: a) scanf("%jd", &ai);
  for (auto& bi: b) scanf("%jd", &bi);

  unsigned res = 0;
  for (intmax_t i = 1 << 29; i; i >>= 1) {
    std::sort(b.begin(), b.end());
    unsigned cur = 0;
    for (auto ai: a) {
      {
        intmax_t lb = i-ai;
        intmax_t ub = lb+i;
        auto il = std::lower_bound(b.begin(), b.end(), lb);
        auto iu = std::lower_bound(b.begin(), b.end(), ub);
        cur += iu-il;
      }
      {
        intmax_t lb = 3*i-ai;
        intmax_t ub = lb+i;
        auto il = std::lower_bound(b.begin(), b.end(), lb);
        auto iu = std::lower_bound(b.begin(), b.end(), ub);
        cur += iu-il;
      }
    }
    if (cur & 1) res |= i;

    for (auto& ai: a) ai &= i-1;
    for (auto& bi: b) bi &= i-1;
  }

  printf("%u\n", res);
}
