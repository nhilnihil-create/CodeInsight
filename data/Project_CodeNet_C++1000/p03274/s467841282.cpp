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
  cin >> N >> K;
  vector<int64_t> X(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> X[i];
  }
  if (0 <= X[0]) {
    cout << X[K - 1] << endl;
    return 0;
  }
  if (X[N - 1] <= 0) {
    cout << abs(X[N - K]) << endl;
    return 0;
  }

  int64_t right = static_cast<int64_t>(lower_bound(X.begin(), X.end(), 0) - X.begin());
  int64_t left = (X[right] == 0) ? right : right - 1;
  int64_t result = INT64_MAX;
  if (left >= 0 && left < N) {
    for (int64_t i = left; left - i + 1 <= K && i >= 0; --i) {
      const int64_t remaining = K - (left - i + 1);
      const int64_t temp_1 = abs(X[i]);
      const int64_t right_end = right + remaining - 1;
      if (right_end >= 0 && right_end < N) {
        const int64_t temp_2 = abs(X[i]) + X[right_end];
        result = min(result, temp_1 + temp_2);
      }
    }
  }
  if (right >= 0 && right < N) {
    for (int64_t i = right; i - right + 1 <= K && i < N; ++i) {
      const int64_t remaining = K - (i - right + 1);
      const int64_t temp_1 = X[i];
      const int64_t left_end = left - (remaining - 1);
      if (left_end >= 0 && left_end < N) {
        const int64_t temp_2 = X[i] + abs(X[left_end]);
        result = min(result, temp_1 + temp_2);
      }
    }
  }

  cout << result << endl;
  return 0;
}
