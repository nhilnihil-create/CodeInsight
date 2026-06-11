#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  string S;
  cin >> S;
  int N = S.size();

  const int64_t mod = 1e9 + 7;
  vector<vector<int64_t>> DP(N + 1, vector<int64_t>(4, 0));
  DP[0][0] = 1;
  rep(i, N) {
    for (int j = 0; j < 4; ++j) {
      if (S[i] == '?') {
        DP[i + 1][j] = (DP[i + 1][j] + (DP[i][j] * 3) % mod) % mod;
      } else {
        DP[i + 1][j] = (DP[i + 1][j] + DP[i][j]) % mod;
      }
      if (j < 3) {
        if (S[i] == (j + 'A') || S[i] == '?') {
          DP[i + 1][j + 1] = (DP[i + 1][j + 1] + DP[i][j]) % mod;
        }
      }
    }
  }
  cout << DP[N][3] << endl;
  return 0;
}