#include <algorithm>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, K;
  cin >> N >> K;
  vector<pair<int64_t, int64_t>> XY(N);
  vector<int64_t> X(N);
  vector<int64_t> Y(N);
  rep(i, N) {
    int64_t x, y;
    cin >> x >> y;
    XY[i] = {x, y};
    X[i] = x;
    Y[i] = y;
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());

  int64_t answer = INT64_MAX;
  for (int xi = 0; xi < N - 1; ++xi) {
    for (int xj = xi + 1; xj < N; ++xj) {
      for (int yi = 0; yi < N - 1; ++yi) {
        for (int yj = yi + 1; yj < N; ++yj) {
          int count = 0;
          for (int k = 0; k < N; ++k) {
            if ((X[xi] <= XY[k].first && XY[k].first <= X[xj]) &&
                (Y[yi] <= XY[k].second && XY[k].second <= Y[yj]))
              ++count;
          }
          if (K <= count) {
            int64_t area = abs(X[xi] - X[xj]) * abs(Y[yi] - Y[yj]);
            answer = min(answer, area);
          }
        }
      }
    }
  }
  cout << answer << endl;
  return 0;
}