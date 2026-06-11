#include <cstdio>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>

struct {
  using value_type = std::tuple<size_t, size_t, intmax_t>;
  bool operator ()(const value_type& lhs, const value_type& rhs) const {
    size_t w0, s0, w1, s1;
    intmax_t v0, v1;
    std::tie(w0, s0, v0) = lhs;
    std::tie(w1, s1, v1) = rhs;
    return w0 + s0 < w1 + s1;
  }
} cmp;

int main() {
  size_t N;
  scanf("%zu", &N);

  std::vector<std::tuple<size_t, size_t, intmax_t>> a(N);
  size_t wsum = 0;
  for (auto& ai: a) {
    size_t w, s;
    intmax_t v;
    scanf("%zu %zu %jd", &w, &s, &v);
    ai = std::make_tuple(w, s, v);
    wsum += w;
  }
  std::sort(a.begin(), a.end(), cmp);

  std::vector<intmax_t> dp(wsum+1);
  for (size_t i = 0; i < N; ++i) {
    size_t w, s;
    intmax_t v;
    std::tie(w, s, v) = a[i];
    for (size_t j = s+1; j--;) {
      if (j+w > wsum) continue;
      dp[j+w] = std::max(dp[j+w], dp[j]+v);
    }
  }

  printf("%jd\n", *std::max_element(dp.begin(), dp.end()));
}
