#include <bits/stdc++.h>

using namespace std;

#define range(i, m, n) for(int i = m; i < n; i++)
#define husk(i, m, n) for(int i = m; i > n; i--)

int n, h, w;

int main() {
  cin >> h >> w >> n;
  set<pair<int, int>> obs;
  vector<vector<int>> to(w);
  range(i, 0, n) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    if(x < y) continue;
    to[y].push_back(x);
    obs.insert(make_pair(x, y));
  }
  range(i, 0, w) {
    to[i].push_back(h);
    sort(to[i].begin(), to[i].end());
  }
  range(x, 0, h) obs.insert(make_pair(x, w));
  range(y, 0, w) obs.insert(make_pair(h, y));
  int x = 0;
  int y = 0;
  vector<pair<int, int>> cur;
  auto ted = [&]() {
    if(cur.size() < 3) {
      if(cur.size() == 2) {
        return (cur[0] == cur[1] && cur[0] == make_pair(0, 0));
      }
      return false;
    }
    int sz = cur.size();
    return (cur[sz - 1] == cur[sz - 2] && cur[sz - 2] == cur[sz - 3]);
  };
  while(true) {
    if(obs.find(make_pair(x + 1, y)) != obs.end()) {
      cur.emplace_back(x, y);
      if(ted()) break;
      cur.emplace_back(x, y);
      break;
    }
    x++;
    cur.emplace_back(x, y);
    int c = obs.find(make_pair(x, y + 1)) == obs.end();
    y += c;
    cur.emplace_back(x, y);
  }
  int res = cur.size();
  for(int i = 0; i < (int) cur.size(); i += 2) {
    int u = cur[i].first, v = cur[i].second;
    int su = *lower_bound(to[v].begin(), to[v].end(), u);
    res = min(res, i + 1 + (su - u) * 2);
  }
  cout << (res + 1) / 2;
  return 0;
}
