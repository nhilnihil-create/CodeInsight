/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N, K;
  string S;
  cin >> N >> K >> S;
  vector<Pair> ones;
  int64_t start_of_one = -1;
  for (int64_t i = 0; i < N; ++i) {
    if (S[i] == '0') {
      // zero
      if (i - 1 >= 0 && S[i - 1] == '1') {
        ones.emplace_back(start_of_one, i - 1);
        start_of_one = -1;
      }
    } else {
      // one
      if (start_of_one < 0) {
        start_of_one = i;
      }
    }
  }
  if (S[N - 1] == '1') {
    ones.emplace_back(start_of_one, N - 1);
  }
  if (ones.size() == 0) {
    std::cout << N << endl;
    return 0;
  }
  int64_t result = ones[min(K - 1, static_cast<int64_t>(ones.size()) - 1)].second + 1;
  result = max(result, N - ones[ones.size() - K].first);
  for (int64_t i = 0; i < static_cast<int64_t>(ones.size()); ++i) {
    const int64_t end = min(i + K, static_cast<int64_t>(ones.size()) - 1);
    result = max(result, ones[end].second - ones[i].first + 1);
  }
  std::cout << result << endl;
  return 0;
}
