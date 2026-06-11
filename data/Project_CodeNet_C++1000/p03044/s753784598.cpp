#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

struct Edge {
  int to, dist;
  Edge (int a, int b) : to(a), dist(b) {}
};

vector<vector<Edge>> G;
vector<int> colors;

void dfs(int v, int c) {
  for (const auto& e : G[v]) {
    int u = e.to;
    int w = e.dist;
    int nc = (w % 2 == 0) ? c : -c;
    if (colors[u] == 0) {
      colors[u] = nc;
      dfs(u, nc);
    }
  }
}

int main() {
  int N; cin >> N;
  G.resize(N);
  colors.resize(N, 0);

  for (int i = 0; i < N-1; ++i) {
    int u, v, w; cin >> u >> v >> w; --u, --v;
    G[u].push_back(Edge(v, w));
    G[v].push_back(Edge(u, w));
  }

  colors[0] = 1;
  dfs(0, 1);
  for (int c : colors) {
    cout << max(c, 0) << endl;
  }
}
