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
  vector<int64_t> C(N - 1);
  vector<int64_t> S(N - 1);
  vector<int64_t> F(N - 1);
  for (int64_t i = 0; i <= N - 2; ++i) {
    cin >> C[i] >> S[i] >> F[i];
  }
  for (int64_t start = 0; start <= N - 2; ++start) {
    int64_t c_time = S[start];
    for (int64_t i = start; i <= N - 2; ++i) {
      if (c_time % F[i] == 0) {
        c_time = max(c_time, S[i]);
      } else {
        c_time = max(((c_time / F[i]) + 1) * F[i], S[i]);
      }
      c_time += C[i];
    }
    cout << c_time << endl;
  }
  cout << 0 << endl;

  return 0;
}
