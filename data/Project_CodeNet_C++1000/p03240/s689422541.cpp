#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace std;

struct Pyramid {
  int64_t x;
  int64_t y;
  int64_t h;
};

int main() {
  int N;
  cin >> N;
  int64_t valid_x = -1, valid_y = -1, valid_h = -1;
  vector<Pyramid> ps(N);
  for (int n = 0; n < N; ++n) {
    cin >> ps[n].x >> ps[n].y >> ps[n].h;
    if (valid_x == -1 && ps[n].h != 0) {
      valid_x = ps[n].x, valid_y = ps[n].y, valid_h = ps[n].h;
    }
  }
  for (int64_t cx = 0; cx <= 100; ++cx) {
    for (int64_t cy = 0; cy <= 100; ++cy) {
      bool find = true;
      int64_t H = valid_h + abs(valid_x - cx) + abs(valid_y - cy);
      for (int n = 0; n < N; ++n) {
        const Pyramid& p = ps[n];
        if (p.h != max(H - abs(p.x - cx) - abs(p.y - cy), static_cast<int64_t>(0))) {
          find = false;
          break;
        }
      }
      if (find) {
        cout << cx << " " << cy << " " << H << endl;
        return 0;
      }
    }
  }
  return -1;
}
