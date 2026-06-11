#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
#include <bitset>
#include <vector>

using namespace std;
using Graph = vector<vector<long long>>;

vector<long long> color;

long long N, M;

long long black = 0;
long long white = 0;

bool dfs(const Graph &G, long long v, long long cur = 0) {
  color[v] = cur;

  for (auto next_v : G[v]) {
    if (color[next_v] != -1) {
      if (color[next_v] == cur) {
        return false;
      } else {
        continue;
      }
    }
    if (!dfs(G, next_v, 1 - cur)) return false;
  }
  return true;
}

int main() {
  cin >> N >> M;

  Graph G(N);

  for (long long i = 0; i < M; i++) {
    long long a, b;
    cin >> a >> b;
    a--;
    b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }

  color.assign(N, -1);
  bool is_bipartite = true;
  for (long long v = 0; v < N; v++) {
    if (color[v] != -1) continue;
    if (!dfs(G, v)) is_bipartite = false;
  }

  if (is_bipartite) {
    for (auto i : color) {
      black = (i == 0) ? black + 1 : black;
      white = (i == 1) ? white + 1 : white;
    }
    cout << black * white - M << endl;
  } else {
    cout << (N * (N -1)) / 2 - M << endl;
  }
  
}
