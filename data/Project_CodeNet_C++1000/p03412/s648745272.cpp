#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 200'009;

int a[N];
int b[N];
vector<int> wb[2];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", b + i);
  }
  int ans = 0;
  for (int i = 0; i <= 29; ++i) {
    for (int j = 0; j < 2; ++j) {
      wb[j].clear();
    }
    for (int j = 0; j < n; ++j) {
      wb[b[j] >> i & 1].push_back(b[j] & ((1 << i) - 1));
    }
    for (int j = 0; j < 2; ++j) {
      sort(wb[j].begin(), wb[j].end());
    }
    int xr = 0;
    for (int j = 0; j < n; ++j) {
      int va = a[j] >> i & 1;
      int wa = a[j] & ((1 << i) - 1);
      for (int vb = 0; vb < 2; ++vb) {
        int l = -1, r = (int)wb[vb].size();
        while (r - l > 1) {
          int s = (l + r) / 2;
          if (wb[vb][s] + wa < (1 << i)) {
            l = s;
          } else {
            r = s;
          }
        }
        if ((l + 1) % 2 == 1) {
          xr ^= va ^ vb;
        }
        if (((int)wb[vb].size() - l - 1) % 2 == 1) {
          xr ^= va ^ vb ^ 1;
        }
      }
    }
    ans += xr << i;
  }
  printf("%d\n", ans);
}
