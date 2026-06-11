#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<vector<int>> F(N, vector<int>(10));
  rep(i, N) {
    rep(j, 10) { cin >> F[i][j]; }
  }
  vector<vector<int>> P(N, vector<int>(11));
  rep(i, N) {
    rep(j, 11) { cin >> P[i][j]; }
  }

  int64_t answer = INT64_MIN;
  for (int i = 1; i < (1 << 10); ++i) {
    vector<int> C(N, 0);
    int day = 0;
    int plan = i;
    while (plan) {
      if (plan & 1) {
        rep(j, N) {
          if (F[j][day]) C[j]++;
        }
      }
      plan /= 2;
      ++day;
    }

    int64_t profit = 0;
    rep(j, N) { profit += P[j][C[j]]; }
    answer = max(answer, profit);
  }
  cout << answer << endl;
  return 0;
}