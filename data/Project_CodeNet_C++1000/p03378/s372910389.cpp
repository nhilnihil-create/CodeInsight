/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

bool IsAcgt(const char ch) {
  return (ch == 'A' || ch == 'C' || ch == 'G' || ch == 'T');
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int32_t N, M, X;
  cin >> N >> M >> X;
  vector<int32_t> A(M);
  for (int32_t i = 0; i < M; ++i) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  int32_t count_left = 0, count_right = 0;
  for (int32_t i = 0; i < M; ++i) {
    if (A[i] < X && (i == M - 1 || X < A[i + 1])) {
      count_left = i + 1;
      count_right = M - count_left;
      break;
    }
  }
  cout << min(count_left, count_right) << endl;

  return 0;
}
