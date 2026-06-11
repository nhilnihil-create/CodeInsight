#include <bits/stdc++.h>
using namespace std;

struct Coordinate {
  int x;
  int y;
  Coordinate() : x(0), y(0) {}
};

int main() {
  int N, K;
  cin >> N >> K;
  vector<int64_t> X(N);
  vector<int64_t> Y(N);
  vector<Coordinate> coords(N);
  for (int i = 0; i < N; i++) {
    cin >> X.at(i) >> Y.at(i);
    coords.at(i).x = X.at(i);
    coords.at(i).y = Y.at(i);
  }
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  int64_t ans = numeric_limits<int64_t>::max();
  for (int ix_min = 0; ix_min < N - 1; ix_min++) {
    for (int ix_max = ix_min + 1; ix_max < N; ix_max++) {
      for (int iy_min = 0; iy_min < N - 1; iy_min++) {
        for (int iy_max = iy_min + 1; iy_max < N; iy_max++) {
          int64_t xmin = X.at(ix_min);
          int64_t xmax = X.at(ix_max);
          int64_t ymin = Y.at(iy_min);
          int64_t ymax = Y.at(iy_max);
          // 内部の点の数を数える
          int count = 0;
          for (int i = 0; i < N; i++) {
            if (xmin <= coords.at(i).x && coords.at(i).x <= xmax && ymin <= coords.at(i).y && coords.at(i).y <= ymax){
              count++;
            }
          }
          if (K <= count) {
            ans = min(ans, static_cast<int64_t>(xmax - xmin) * static_cast<int64_t>(ymax - ymin));
          }
        }
      }
    }
  }
  cout << ans << endl;
}