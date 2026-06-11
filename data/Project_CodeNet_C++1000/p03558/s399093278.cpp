#include <bits/stdc++.h>
using namespace std;

const int MAX_N = (int)(1e5 + 5);
using pp = pair<int, int>;
bool vis[MAX_N];

int k;
deque<pp> dq;

int solve() {
  fill(vis, vis + MAX_N, false);

  dq.push_front(pp(1, 1));

  while (!dq.empty()) {
    pp p = dq.front(); dq.pop_front();
    int cur = p.first; int cnt = p.second;

    if (cur == 0) return cnt;
    vis[cur] = true;

    int next = (cur + 1) % k;
    if (!vis[next]) {
      dq.push_back(pp(next, cnt + 1));
    }

    next = (cur * 10) % k;
    if (!vis[next]) {
      dq.push_front(pp(next, cnt));
    }
  }
}

int main(void) {
  // Here your code !
  scanf("%d", &k);

  int ans = solve();
  printf("%d\n", ans);

  return 0;
}
