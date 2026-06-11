/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

std::vector<std::pair<int64_t, int64_t>> FactorizeIntoPrimeFactors(const int64_t N) {
  std::vector<std::pair<int64_t, int64_t>> result;
  if (N <= 0LL || N == 1LL) {
    return result;
  }
  int64_t remaining = N;
  for (int64_t i = 2LL; i * i <= remaining; ++i) {
    int64_t count = 0LL;
    while (remaining % i == 0LL) {
      ++count;
      remaining /= i;
    }
    if (count > 0LL) {
      result.push_back(std::pair<int64_t, int64_t>(i, count));
    }
  }
  if (remaining > 1) {
    result.push_back(std::pair<int64_t, int64_t>(remaining, 1));
  }
  return result;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N, M;
  cin >> N >> M;
  int64_t result = -1;
  const int64_t limit = static_cast<int64_t>(sqrt(static_cast<double>(M)));
  for (int64_t i = 1; i <= limit; ++i) {
    if (M % i == 0) {
      if (i >= N) {
        result = max(result, M / i);
      }
      const int64_t j = M / i;
      if (j >= N) {
        result = max(result, M / j);
      }
    }
  }
  if (result < 0) {
    result = 1;
  }
  cout << result << endl;
  return 0;
}
