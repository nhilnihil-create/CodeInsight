#include <bits/stdc++.h>
using namespace std;

int main() {
  int h, w, n;
  scanf("%d %d %d", &h, &w, &n);
  set<pair<int, int>> s, rs;
  for (int i = 0; i < n; ++i) {
    int y, x;
    scanf("%d %d", &y, &x);
    s.emplace(y, x);
    rs.emplace(x, y);
  }
  for (int i = 1; i <= w; ++i) {
    s.emplace(h + 1, i);
    rs.emplace(i, h + 1);
  }
  for (int i = 1; i <= h; ++i) {
    s.emplace(i, w + 1);
    rs.emplace(w + 1, i);
  }
  int uy = 1, ux = 1;
  set<pair<int, int>> reachable;
  int turn = 0;
  while (true) {
    if (turn == 0) {
      if (s.find({uy + 1, ux}) != s.end())
        break;
      ++uy;
    } else {
      if (s.find({uy, ux + 1}) == s.end()) {
        auto p = *rs.lower_bound({ux, uy});;
        reachable.insert(*s.lower_bound({p.second, p.first}));
        ++ux;
      }
    }
    turn ^= 1;
  }
  auto p = *rs.lower_bound({ux, uy});
  reachable.insert(*s.lower_bound({p.second, p.first}));
  int ans = -1;
  for (auto p : s)
    if (reachable.find(p) != reachable.end())
      if (ans == -1 || p.first - 1 < ans)
        ans = p.first - 1;
  printf("%d\n", ans);
  return 0;
}