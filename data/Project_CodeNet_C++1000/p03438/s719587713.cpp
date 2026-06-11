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

  int64_t N;
  cin >> N;
  // const int64_t L = static_cast<int64_t>(T.length());
  vector<int64_t> A(N);
  vector<int64_t> B(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> A[i];
  }
  queue<int64_t> B_is_smaller;
  queue<int64_t> A_is_smaller;
  int64_t total_count = 0;
  int64_t increment_b = 0;
  int64_t increment_a = 0;
  for (int64_t i = 0; i < N; ++i) {
    cin >> B[i];
    total_count += (B[i] - A[i]);
    if (A[i] > B[i]) {
      increment_b += (A[i] - B[i]);
    } else if (A[i] < B[i]) {
      increment_a += (B[i] - A[i] + 1) / 2;
      increment_b += ((B[i] - A[i]) % 2);
    }
  }

  if (increment_a > total_count) {
    cout << "No" << endl;
  } else if (increment_b > total_count) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
  return 0;
}
