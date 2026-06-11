#include <algorithm>
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
vector<int> colors;
LL N, M;

bool dfs(int v, int c) {
  colors[v] = c;
  for (const auto& n : G[v]) {
    if (colors[n] == c) return false;
    if (colors[n] == 0 && !dfs(n, -c)) return false;
  }
  return true;
}

bool is_bipartite_graph() {
  for (int i = 1; i <= N; ++i) {
    if (colors[i] == 0) {
      if (!dfs(i, 1)) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  cin >> N >> M;
  G.resize(N+1);
  colors.resize(N+1, 0);

  for (int i = 0; i < M; ++i) {
    int A, B; cin >> A >> B;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  if (is_bipartite_graph()) {
    LL cnta = 0, cntb = 0;
    for (int i = 1; i <= N; ++i) {
      if (colors[i] < 0) ++cnta;
      else       ++cntb;
    }
    cout << cnta*cntb - M << endl;
  } else {
    cout << N*(N-1LL)/2LL - M << endl;
  }
}
