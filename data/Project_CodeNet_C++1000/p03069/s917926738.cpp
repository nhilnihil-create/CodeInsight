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

  int64_t N;
  cin >> N;
  string S;
  cin >> S;
  vector<int64_t> A(N + 1, 0);
  int64_t count_black = 0;
  A[0] = 0;
  for (int64_t i = 1; i <= N; ++i) {
    if (S.c_str()[i - 1] == '#') {
      ++count_black;
    }
    A[i] = count_black;
  }
  int64_t result = INT64_MAX;
  for (int64_t black_start = 1; black_start <= N + 1; ++black_start) {
    const int64_t reverse_left = A[black_start - 1];
    const int64_t reverse_right = N - (black_start - 1) - (A[N] - A[black_start - 1]);
    const int64_t count = reverse_left + reverse_right;
    if (count < result) {
      result = count;
    }
  }
  cout << result << endl;
  return 0;
}
