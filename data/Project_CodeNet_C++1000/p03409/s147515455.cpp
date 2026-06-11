#include <bits/stdc++.h>
using namespace std;
struct edge {
  int to, cap, rev;
};

vector<vector<edge>> e;
vector<int> used;

int dfs(int v, int t, int f) {
  if(v == t) return f;
  used[v] = 1;
  for(int i = 0; i < e[v].size(); i++) {
    if(e[v][i].cap && !used[e[v][i].to]) {
      int d = dfs(e[v][i].to, t, min(f, e[v][i].cap));
      if(d) {
        e[v][i].cap -= d;
        e[e[v][i].to][e[v][i].rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int main() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> r(n);
  e = vector<vector<edge>>(2 * n + 2, vector<edge>());
  for(int i = 1; i <= n; i++) {
    e[0].push_back(edge{i, 1, e[i].size()});
    e[i].push_back(edge{0, 0, e[0].size() - 1});
    e[n + i].push_back(edge{2 * n + 1, 1, e[2 * n + 1].size()});
    e[2 * n + 1].push_back(edge{n + i, 0, e[n + i].size() - 1});
  }
  for(int i = 0; i < n; i++) scanf("%d %d", &r[i].first, &r[i].second);
  for(int i = 0; i < n; i++) {
    int c, d;
    scanf("%d %d", &c, &d);
    for(int j = 0; j < n; j++) {
      if(r[j].first < c && r[j].second < d) {
        e[i + 1].push_back(edge{j + 1 + n, 1, e[j + 1 + n].size()});
        e[j + 1 + n].push_back(edge{i + 1, 0, e[i + 1].size() - 1});
      }
    }
  }
  used = vector<int>(2 * n + 2, 0);
  int flow = 0, f;
  do {
    fill(used.begin(), used.end(), 0);
    f = dfs(0, 2 * n + 1, INT_MAX);
    flow += f;
  } while(f);
  printf("%d\n", flow);
}