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

  int64_t N, H;
  cin >> N >> H;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<int64_t> A(N);
  vector<int64_t> B(N);
  int64_t max_a = INT64_MIN;
  for (int64_t i = 0; i < N; ++i) {
    cin >> A[i] >> B[i];
    if (A[i] > max_a) {
      max_a = A[i];
    }
  }
  sort(B.begin(), B.end());
  reverse(B.begin(), B.end());
  int64_t sum_b = 0;
  for (int64_t i = 0; i < N; ++i) {
    if (B[i] > max_a) {
      sum_b += B[i];
    } else {
      break;
    }
  }
  int64_t result = 0;
  if (H > sum_b) {
    const int64_t count_a = (H - sum_b + (max_a - 1)) / max_a;
    result += count_a;
    H -= count_a * max_a;
  }
  for (int64_t i = 0; i < N; ++i) {
    if (H <= 0) {
      break;
    }
    H -= B[i];
    ++result;
  }

  cout << result << endl;
  return 0;
}
