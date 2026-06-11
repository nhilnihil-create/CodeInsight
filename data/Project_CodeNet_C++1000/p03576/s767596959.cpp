#include <bits/stdc++.h>

using namespace std;

struct Point
{
  int64_t x, y;
  Point(int64_t x = 0, int64_t y = 0) : x(x), y(y) {}
};

istream& operator>>(istream &is, Point &p)
{
  is >> p.x >> p.y;
  return is;
}

int main()
{
  uint64_t N, K;
  cin >> N >> K;
  
  vector<int64_t> x(N), y(N);
  vector<Point> p(N);
  
  for (uint64_t n = 0; n < N; ++n) {
    cin >> p[n];
    
    x[n] = p[n].x;
    y[n] = p[n].y;
  }
  
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  
  uint64_t s_min = 1e+20;
  for (uint64_t ix = 0; ix < N; ++ix) {
    int64_t x_min = x[ix];
    for (uint64_t iy = 0; iy < N; ++iy) {
      int64_t y_min = y[iy];
      for (uint64_t jx = ix + 1; jx < N; ++jx) {
        int64_t x_max = x[jx];
        for (uint64_t jy = iy + 1; jy < N; ++jy) {
          int64_t y_max = y[jy];
          
          uint64_t k = 0;
          for (uint64_t l = 0; l < N; ++l) {
            if ( (x_min <= p[l].x && p[l].x <= x_max)
              && (y_min <= p[l].y && p[l].y <= y_max)  
            ) {
              ++k;
            }
          }
          
          if (k >= K) {
            uint64_t s = (x_max - x_min) * (y_max - y_min);
            s_min = min(s_min, s);
          }
        }
      }
    }
  }
  cout << s_min << endl;
  
  return 0;
}