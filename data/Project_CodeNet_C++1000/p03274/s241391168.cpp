/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int64_t, int64_t>;

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

  int64_t result = INT64_MAX;
  for (int64_t start_index = 0; start_index + K <= N; ++start_index) {
    const int64_t start = X[start_index];
    const int64_t end = X[start_index + K - 1];
    if (start >= 0) {
      result = min(result, end);
    } else if (end <= 0) {
      result = min(result, -start);
    } else {
      result = min(result, -start * 2 + end);
      result = min(result, end * 2 - start);
    }
  }
  cout << result << endl;

  return 0;
}
