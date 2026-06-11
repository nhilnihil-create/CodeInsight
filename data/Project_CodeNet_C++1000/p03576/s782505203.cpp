#include <iostream>
#include <vector>
using namespace std;

using int64 = long long;
using PII = pair<int64, int64>;

int64 CountInside(int64 x0, int64 y0, int64 x1, int64 y1, const vector<PII>& xys) {
  int64 res = 0;
  for (auto& xy : xys) {
    if (x0 <= xy.first && xy.first <= x1 &&
        y0 <= xy.second && xy.second <= y1)
      ++res;
  }
  return res;
}

int main() {
  int64 n, k;
  cin >> n >> k;
  vector<PII> xys(n);
  for (auto& xy : xys)
    cin >> xy.first >> xy.second;

  int64 res = 4e+18;
  for (int64 i0 = 0; i0 < n; ++i0) {
    auto& xy0 = xys[i0];
    for (int64 i1 = i0; i1 < n; ++i1) {
      auto& xy1 = xys[i1];
      for (int64 i2 = i1; i2 < n; ++i2) {
        auto& xy2 = xys[i2];
        for (int64 i3 = i2; i3 < n; ++i3) {
          auto& xy3 = xys[i3];
          int64 x0 = min(min(xy0.first, xy1.first), min(xy2.first, xy3.first));
          int64 x1 = max(max(xy0.first, xy1.first), max(xy2.first, xy3.first));
          int64 y0 = min(min(xy0.second, xy1.second), min(xy2.second, xy3.second));
          int64 y1 = max(max(xy0.second, xy1.second), max(xy2.second, xy3.second));
          int64 count = CountInside(x0, y0, x1, y1, xys);
          if (count < k)
            continue;
          int64 area = max<int64>(x1 - x0, 1) * max<int64>(y1 - y0, 1);
          res = min(res, area);
        }
      }
    }
  }
  cout << res << "\n";

  return 0;
}
