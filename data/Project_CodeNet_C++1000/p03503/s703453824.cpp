/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

// std::cout << std::setprecision(20) << 1.1 << endl;

int64_t F[100][5][2];
int64_t P[100][11];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N;
  cin >> N;
  for (int64_t i = 0; i < N; ++i) {
    for (int64_t j = 0; j < 5; ++j) {
      for (int64_t k = 0; k < 2; ++k) {
        cin >> F[i][j][k];
      }
    }
  }
  for (int64_t i = 0; i < N; ++i) {
    for (int64_t c = 0; c <= 10; ++c) {
      cin >> P[i][c];
    }
  }
  int64_t result = -kInf;
  for (int64_t b = 1; b < (1 << 10); ++b) {
    bitset<10> bs(b);
    vector<int64_t> C(N, 0);
    for (int64_t j = 0; j < 5; ++j) {
      for (int64_t k = 0; k < 2; ++k) {
        if ((bs[k + j * 2])) {
          for (int64_t i = 0; i < N; ++i) {
            if (F[i][j][k]) {
              ++C[i];
            }
          }
        }
      }
    }
    int64_t temp = 0;
    for (int64_t i = 0; i < N; ++i) {
      temp += P[i][C[i]];
    }
    result = max(result, temp);
  }
  cout << result << endl;
  return 0;
}
