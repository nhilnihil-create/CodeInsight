#include <bits/stdc++.h>

using namespace std;

#define FOR(var, start, end) for (int var = start; var < end; var++)
#define REP(var, cnt) FOR(var, 0, cnt)

int A[110][2];
vector<int> edges[110];

int matched[110];

int dfs(int v, vector<int> &visited) {
  for (int u : edges[v]) {
    if (find(visited.begin(), visited.end(), u) != visited.end()) {
      continue;
    }

    visited.push_back(u);

    if (matched[u] == -1 || dfs(matched[u], visited)) {
      matched[u] = v;
      return 1;
    }
  }
  return 0;
}

int main(void) {
  int N;
  cin >> N;

  REP(i, N) {
    int x, y;
    cin >> x >> y;
    A[i][0] = x;
    A[i][1] = y;

    matched[i] = -1;
  }

  REP(i, N) {
    int x, y;
    cin >> x >> y;

    REP(j, N) {
      if (A[j][0] < x && A[j][1] < y) {
        edges[i].push_back(j);
      }
    }
  }

  int ret = 0;
  REP(i, N) {
    vector<int> aa;
    ret += dfs(i, aa);
  }

  cout << ret << endl;
}
