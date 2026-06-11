#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N;
  cin >> N;
  vector<int> C(N);
  vector<vector<int>> P(2e5 + 1);
  rep(i, N) {
    cin >> C[i];
    P[C[i]].emplace_back(i);
  }

  vector<int64_t> DP(2e5 + 1, 0);
  const int64_t mod = 1e9 + 7;
  DP[0] = 1;
  rep(i, N) {
    DP[i + 1] = (DP[i + 1] + DP[i]) % mod;

    auto itr = lower_bound(P[C[i]].begin(), P[C[i]].end(), i);
    if (itr != P[C[i]].end()) {
      int pos = itr - P[C[i]].begin();
      if (pos == 0) continue;
      int j = P[C[i]][pos - 1];
      if (j + 1 < i) {
        DP[i + 1] = (DP[i + 1] + DP[j + 1]) % mod;
      }
    }
  }
  cout << DP[N] << endl;
  return 0;
}
