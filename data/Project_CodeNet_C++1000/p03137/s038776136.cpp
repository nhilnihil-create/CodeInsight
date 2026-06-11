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
  vector<Pair> ds(M - 1);
  for (int64_t i = 1; i < M; ++i) {
    ds[i - 1].first = X[i] - X[i - 1];
    ds[i - 1].second = i;
  }
  sort(ds.begin(), ds.end());
  reverse(ds.begin(), ds.end());

  vector<int64_t> starts;
  starts.emplace_back(0);
  for (const auto a : ds) {
    if (static_cast<int64_t>(starts.size()) >= N) {
      break;
    }
    starts.emplace_back(a.second);
  }
  sort(starts.begin(), starts.end());

  int64_t result = 0;
  for (int64_t i = 0; i < N; ++i) {
    if (i == N - 1) {
      result += X[M - 1] - X[starts[i]];
    } else {
      result += X[starts[i + 1] - 1] - X[starts[i]];
    }
  }
  cout << result << endl;
  return 0;
}
