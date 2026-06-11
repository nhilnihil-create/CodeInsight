#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using Graph = vector<vector<int>>;
vector<int> color;
//int judge = -1;

bool dfs(const Graph &G, int v, int c) {
  color[v] = c;
  for (auto nv : G[v]) {
    if (color[nv] == -c) continue;
    else if (color[nv] == c) {
      //judge = 1;
      return false;
    }
    else {
      if(!dfs(G, nv, -c)) return false;
    }
  }
  return true;
}

int main() {
  int64_t N, M;
  cin >> N >> M;
  
  Graph G(N);
  
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  color.assign(N, 0);
  
  if (dfs(G, 0, 1)) {
    int64_t count_1 = 0;
    for (int i = 0; i < N; i++) {
      if (color[i] == 1)
        count_1++;
    }
    
    int64_t a = count_1 * (N - count_1) - M;
    cout << a << endl;
  }
  else {
    int64_t b = N * (N - 1) / 2 - M;
    cout << b << endl;
  }
}
    