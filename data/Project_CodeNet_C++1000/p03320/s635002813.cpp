#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <string>

intmax_t ds(intmax_t n) {
  intmax_t res = 0;
  while (n) {
    res += n % 10;
    n /= 10;
  }
  return res;
}

intmax_t f(intmax_t n) {
  std::string s = std::to_string(n);
  intmax_t res = n;

  auto cmp = [&](__int128 u, __int128 v) { return u*ds(v) < v*ds(u); };

  // "1234567"
  for (size_t i = 0; i < s.length(); ++i) {
    // "12x9999"
    std::string t = s.substr(0, i) + std::string(s.length()-i, '9');
    while (t[i] <= '9') {
      res = std::min(res, std::stol(t), cmp);
      ++t[i];
    }
  }

  // "yy9999999"
  __int128 nines = std::stol(std::string(s.length(), '9'));
  for (size_t i = 1; i < 100; ++i) {
    __int128 cur = i * (nines+1) + nines;
    res = std::min<__int128>(res, cur, cmp);
  }

  return res;
}

int main() {
  size_t k;
  scanf("%zu", &k);

  intmax_t n = 1;
  for (size_t i = 0; i < k; ++i) {
    printf("%jd\n", n);
    n = f(n+1);
  }
}
