#include <cstdio>
#include <set>
#include <map>
#include <vector>

int main(void) {
  int w, h, n;
  while (scanf("%d%d%d", &w, &h, &n) == 3) {
    std::vector<std::set<int>> ys(h + 1);
    for (int i = 0; i < n; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      ys[y].insert(x);
    }

    int res = 1000000000;
    int steps = 0;
    int x = 1, y = 1;
    while (true) {
      auto it = ys[y].lower_bound(x);
      int d;
      if (it == ys[y].end()) {
        d = w + 1 - x;
      } else {
        d = *it - x;
      }
      res = std::min(res, steps + d);
      if (d == 1) {
        break;
      }
      x++;
      steps++;
      if (y != h && ys[y + 1].count(x) == 0) {
        y++;
      }
    }
    printf("%d\n", res);
  }
  return 0;
}
