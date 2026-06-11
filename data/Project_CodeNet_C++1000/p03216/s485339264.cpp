#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

intmax_t solve(std::string const& s, size_t k) {
  size_t n = s.length();

  std::vector<size_t> acc(n);
  for (size_t i = 0; i < n; ++i)
    if (s[i] == 'M') acc[i] = 1;
  acc.insert(acc.begin(), 0);
  for (size_t i = 1; i <= n; ++i) acc[i] += acc[i-1];

  intmax_t d = 0;
  intmax_t m = 0;
  intmax_t c = 0;
  for (size_t i = 0; i < n; ++i) {
    if (s[i] == 'D') {
      ++d;
    } else if (s[i] == 'M') {
      m += d;
    } else if (s[i] == 'C') {
      c += m;
    }
    if (i+1 < k) continue;

    if (s[i+1-k] == 'D') {
      --d;
      m -= acc[i+1] - acc[i+1-k];
    }
  }
  return c;
}

int main() {
  size_t n;
  scanf("%zu", &n);
  char buf[1048576];
  scanf("%s", buf);
  std::string s = buf;

  size_t q;
  scanf("%zu", &q);

  for (size_t i = 0; i < q; ++i) {
    size_t k;
    scanf("%zu", &k);
    printf("%jd\n", solve(s, k));
  }
}
