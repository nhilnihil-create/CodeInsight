/**
 * @copyright (c) 2020 Daisuke Hashimoto
 */

#include <bits/stdc++.h>
using namespace std;
using Pair = pair<int64_t, int64_t>;
constexpr int64_t kInf = INT64_MAX / 2L;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N, M;
  cin >> N >> M;
  vector<int64_t> X(M);
  for (int64_t i = 0; i < M; ++i) {
    cin >> X[i];
  }
  if (N >= M) {
    cout << 0 << endl;
    return 0;
  }

  sort(X.begin(), X.end());
  vector<int64_t> ds(M - 1);
  for (int64_t i = 1; i < M; ++i) {
    ds[i - 1] = X[i] - X[i - 1];
  }
  sort(ds.begin(), ds.end());

  for (int64_t i = 0; i < N - 1; ++i) {
    ds.pop_back();
  }
  int64_t result = 0;
  for (int64_t d : ds) {
    result += d;
  }
  cout << result << endl;
  return 0;
}
