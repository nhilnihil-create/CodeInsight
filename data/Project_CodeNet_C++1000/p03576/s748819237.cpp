#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  vector<int64_t> X(N), Y(N), SX(N), SY(N);
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
    SX[i] = X[i];
    SY[i] = Y[i];
  }
  sort(SX.begin(), SX.end());
  sort(SY.begin(), SY.end());
  int64_t res = (SX[N - 1] - SX[0]) * (SY[N - 1] - SY[0]);
  for (int ix = 0; ix < N; ix++) {
    for (int jx = ix + 1; jx < N; jx++) {
      for (int iy = 0; iy < N; iy++) {
        for (int jy = iy + 1; jy < N; jy++) {
          int cnt = 0;
          for (int i = 0; i < N; i++) {
            if (SX[ix] <= X[i] && X[i] <= SX[jx] && SY[iy] <= Y[i] &&
                Y[i] <= SY[jy])
              cnt++;
          }
          if (cnt >= K) res = min(res, (SX[jx] - SX[ix]) * (SY[jy] - SY[iy]));
        }
      }
    }
  }
  cout << res << '\n';
  return 0;
}
