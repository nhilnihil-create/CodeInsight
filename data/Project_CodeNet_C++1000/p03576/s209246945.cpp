#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, K;
  cin >> N >> K;
  vector<int64_t> X(N), Y(N);
  vector<int64_t> XA, YA;
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
    XA.emplace_back(X[i]);
    YA.emplace_back(Y[i]);
  }

  sort(XA.begin(), XA.end());
  sort(YA.begin(), YA.end());

  int64_t res = (XA[N - 1] - XA[0]) * (YA[N - 1] - YA[0]);

  for (int xi = 0; xi < N; xi++) {
    for (int xj = xi + 1; xj < N; xj++) {
      for (int yi = 0; yi < N; yi++) {
        for (int yj = yi + 1; yj < N; yj++) {
          int cnt = 0;
          int64_t lx = XA[xi], rx = XA[xj];
          int64_t by = YA[yi], uy = YA[yj];

          for (int i = 0; i < N; i++) {
            if (lx <= X[i] && X[i] <= rx && by <= Y[i] && Y[i] <= uy) cnt++;
          }

          if (cnt >= K) res = min(res, (rx - lx) * (uy - by));
        }
      }
    }
  }

  cout << res << '\n';

  return 0;
}
