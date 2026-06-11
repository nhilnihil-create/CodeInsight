#include <iostream>
#include <sstream>
#include <algorithm>
#include <functional>
#include <iterator>
#include <numeric>
#include <cstdint>
#include <cmath>
#include <bitset>
#include <string>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

#define N_TIMES(i, n)     for ( uint64_t i = 0;     i <  n; ++i )
#define N_TIMES_REV(i, n) for (  int64_t i = n - 1; i >= 0; --i )

using namespace std;

struct Point
{
  int64_t x, y;
  Point(int64_t x, int64_t y) : x(x), y(y) {}
  int64_t operator-(const Point &p) const {
    return abs(x - p.x) + abs(y - p.y);
  }
};

int main()
{
  uint64_t H, W, D;
  cin >> H >> W >> D;

  vector<Point> A(H * W, Point(0, 0));
  N_TIMES(h, H) {
    N_TIMES(w, W) {
      uint64_t a;
      cin >> a;
      A[a - 1] = Point(w, h);
    }
  }

  uint64_t N = ((H * W) / D) + 1;
  vector<vector<uint64_t>> cumsum(D);
  N_TIMES(i, D) {
    cumsum[i] = vector<uint64_t>(N, 0);
    N_TIMES(n, N - 1) {
      uint64_t k = i + n * D;
      if (k + D >= H * W) { break; }
      cumsum[i][n + 1] = (A[k + D] - A[k]) + cumsum[i][n];
    }
  }

  uint64_t Q;
  cin >> Q;

  N_TIMES(q, Q) {
    uint64_t L, R;
    cin >> L >> R;
    --L, --R;

    uint64_t i = L % D;
    uint64_t n = (L - i) / D, m = (R - i) / D;
    cout << (cumsum[i][m] - cumsum[i][n]) << endl;
  }

  return 0;
}