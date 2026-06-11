#include <bits/stdc++.h>
using namespace std;
#define int long long

struct edge {
  int to, cost;
};

signed main() {
  int K;
  cin >> K;
  vector<bool> vis(K, false);
  deque<pair<int, int>> dq;
  dq.push_back({1, 1});

  while (!dq.empty()) {
    pair<int, int> p = dq.front();
    dq.pop_front();
    int x = p.first, d = p.second;

    if (vis[x]) continue;
    vis[x] = true;

    if (x == 0) {
      cout << d << endl;
      return 0;
    }

    dq.push_back({(x + 1) % K, d + 1});
    dq.push_front({(x * 10) % K, d});
  }

  return 0;
}
