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

vector<vector<int>> G;
vector<LL> dp_b, dp_w;

void mul(LL& a, LL b) { a = (a * b) % kMod; }

void dfs(int v, int parent) {
  for (int u : G[v]) {
    if (u == parent) continue;
    dfs(u, v);
    mul(dp_w[v], dp_w[u] + dp_b[u]);
    mul(dp_b[v], dp_w[u]);
  }
}

int main() {
  int N; cin >> N;
  G.resize(N), dp_b.resize(N, 1), dp_w.resize(N, 1);
  for (int i = 0; i < N-1; ++i) {
    int x, y; cin >> x >> y; --x, --y;
    G[x].push_back(y);
    G[y].push_back(x);
  }

  dfs(0, -1);
  cout << (dp_b[0] + dp_w[0]) % kMod  << endl;
}
