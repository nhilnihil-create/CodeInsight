#include <stdio.h>
#include <vector>
using namespace std;

struct ans_t {
  int x, y, z;

  ans_t(int _x, int _y, int _z) {
    x = _x;
    y = _y;
    z = _z;
  }
};

int main() {
  int n;
  scanf("%d", &n);
  int adder, start, v;
  vector<ans_t> ans;
  for (int bit = 25; bit >= 0; bit--) {
    if (n & (1 << bit)) {
      adder = (1 << bit);
      start = bit;
      for (int i = 0; i < bit; i++) {
        ans.push_back(ans_t(i + 1, i + 2, 0));
        ans.push_back(ans_t(i + 1, i + 2, (1 << i)));
        v = i + 2;
      }
      break;
    }
  }
  for (int bit = start - 1; bit >= 0; bit--) {
    if (n & (1 << bit)) {
      ans.push_back(ans_t(bit + 1, v, adder));
      adder += (1 << bit);
    }
  }
  printf("%d %d\n", v, (int) ans.size());
  for (int i = 0; i < (int) ans.size(); i++) {
    printf("%d %d %d\n", ans[i].x, ans[i].y, ans[i].z);
  }
  return 0;
}