#include <cstdint>
#include <cstdio>
#include <map>
#include <vector>

int main() {
  size_t n;
  int m;
  scanf("%zu %d", &n, &m);

  std::vector<int> a(n);
  for (auto& ai: a) scanf("%d", &ai);

  a.insert(a.begin(), 0);
  for (size_t i = 1; i <= n; ++i)
    a[i] = (a[i-1] + a[i]) % m;

  std::map<int, intmax_t> count;
  for (auto ai: a) ++count[ai];

  intmax_t res = 0;
  for (auto const& p: count) {
    res += p.second * (p.second-1) / 2;
  }

  printf("%jd\n", res);
}
