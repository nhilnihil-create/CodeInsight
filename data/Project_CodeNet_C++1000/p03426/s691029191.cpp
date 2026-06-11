#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, d, q;
  scanf("%d %d %d", &h, &w, &d);
  vector<pair<int, int>> c(h * w + 1);
  vector<vector<int>> m(d, vector<int>(1));
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      int a;
      scanf("%d", &a);
      c[a] = {i, j};
    }
  }
  for(int i = 0; i < d; i++) {
    for(int j = i + 1 + d; j <= h * w; j += d) {
      int nm = m[i].back();
      nm +=
          abs(c[j].first - c[j - d].first) + abs(c[j].second - c[j - d].second);
      m[i].push_back(nm);
    }
  }
  scanf("%d", &q);
  vector<int> o(q);
  for(int i = 0; i < q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    o[i] = m[(l - 1) % d][(r - 1) / d] - m[(l - 1) % d][(l - 1) / d];
  }
  for(int i = 0; i < q; i++) printf("%d\n", o[i]);
}