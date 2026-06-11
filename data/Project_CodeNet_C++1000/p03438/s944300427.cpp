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
  for (int64_t i = 0; i < N; ++i) {
    cin >> B[i];
    if (A[i] > B[i]) {
      B_is_smaller.emplace(A[i] - B[i]);
    } else if (A[i] < B[i]) {
      A_is_smaller.emplace(B[i] - A[i]);
    }
  }

  auto IncrementA = [&](const int64_t amount) -> bool {
    if (A_is_smaller.empty()) {
      return false;
    }
    int64_t remain = amount;
    while (!A_is_smaller.empty()) {
      int64_t d_A_smaller = A_is_smaller.front();
      A_is_smaller.pop();
      if (d_A_smaller >= 2) {
        d_A_smaller = (d_A_smaller / 2) * 2;
      }
      if (remain == d_A_smaller) {
        remain = 0;
        break;
      } else if (remain > d_A_smaller) {
        remain -= d_A_smaller;
      } else {
        d_A_smaller -= remain;
        A_is_smaller.emplace(d_A_smaller);
        remain = 0;
        break;
      }
    }
    if (remain > 0) {
      return false;
    }
    return true;
  };

  while (!B_is_smaller.empty()) {
    int64_t d_B_smaller = B_is_smaller.front();
    B_is_smaller.pop();
    const bool incremented = IncrementA(d_B_smaller * 2);
    if (!incremented) {
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
  return 0;
}
