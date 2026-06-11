#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<vector<int>> train(N + 1, vector<int>(N + 1, 0));
  rep(i, M) {
    int L, R;
    cin >> L >> R;
    train[L][R]++;
  }
  rep(i, N) {
    rep(j, N) { train[i + 1][j + 1] += train[i + 1][j]; }
  }
  rep(i, N) {
    rep(j, N) { train[i + 1][j + 1] += train[i][j + 1]; }
  }

  rep(i, Q) {
    int p, q;
    cin >> p >> q;
    int answer =
        train[q][q] - train[q][p - 1] - train[p - 1][q] + train[p - 1][p - 1];
    cout << answer << endl;
  }
  return 0;
}