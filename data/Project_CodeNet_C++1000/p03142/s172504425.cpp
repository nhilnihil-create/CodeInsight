#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> indeg;  // 入次数
vector<bool> visited;
vector<int> ans;

void bfs(int s) {
  queue<int> q;
  q.push(s);
  visited.at(s) = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    for (int nx : G.at(cur)) {
      if (visited.at(nx)) continue;
      indeg.at(nx)--;
      if (indeg.at(nx) == 0 && !visited.at(nx)) {
        visited.at(nx) = true;
        ans.at(nx) = cur + 1;  // nx の親は cur + 1
        q.push(nx);
      }
    }
  }
}

int main() {
  int N, M; cin >> N >> M;
  G.resize(N);
  indeg.resize(N);
  visited.resize(N);
  ans.resize(N);
  for (int i = 0; i < N-1+M; i++) {
    int a, b; cin >> a >> b;
    a--; b--;
    G.at(a).push_back(b);
  }
  for (int i = 0; i < N; i++) {
    for (int e : G.at(i)) indeg.at(e)++;
  }
  for (int i = 0; i < N; i++) {
    if (indeg.at(i) == 0 && !visited.at(i)) bfs(i);
  }
  for (int v : ans) cout << v << endl;
}