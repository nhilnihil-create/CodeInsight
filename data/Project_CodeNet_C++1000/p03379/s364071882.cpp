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
  vector<int64_t> X(N);
  vector<Pair> Y(N);
  for (int64_t i = 0; i < N; ++i) {
    cin >> X[i];
    Y[i].first = X[i];
    Y[i].second = i;
  }
  sort(Y.begin(), Y.end());
  int64_t left = Y[(N - 1) / 2].second;
  int64_t right = Y[(N - 1) / 2 + 1].second;
  for (int64_t i = 0; i < N; ++i) {
    if (i != 0) {
      cout << " ";
    }
    if (X[i] <= X[left]) {
      cout << X[right];
    } else {
      cout << X[left];
    }
  }
  cout << endl;
  return 0;
}
