/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
using Pair = pair<int32_t, int32_t>;

// std::cout << std::setprecision(20) << 1.1 << endl;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int32_t N, M;
  cin >> N >> M;
  vector<bool> like(M, true);
  for (int32_t i = 0; i < N; ++i) {
    int32_t K;
    cin >> K;
    vector<bool> temp_like(M, false);
    for (int32_t j = 0; j < K; ++j) {
      int32_t a;
      cin >> a;
      const int32_t food_index = a - 1;
      temp_like[food_index] = true;
    }
    for (int32_t j = 0; j < M; ++j) {
      like[j] = like[j] && temp_like[j];
    }
  }
  int32_t count = 0;
  for (int32_t j = 0; j < M; ++j) {
    if (like[j]) {
      ++count;
    }
  }
  cout << count << endl;

  return 0;
}
