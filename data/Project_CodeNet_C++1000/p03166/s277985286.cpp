#include <bits/stdc++.h>
using namespace std;
#define ffor(n) for(int i = 0; i < n; i++)
#define fffor(n) for(int j = 0; j < n; j++)
int INF = 1e9 + 7;

void dfs(vector <bool>& visited, vector <int>& nodes, int node, vector <vector <int>>& asd) {
  if (visited[node]) return;
  visited[node] = true;
  for(auto nextnode: asd[node]) {
    if (visited[nextnode] == false) dfs(visited, nodes, nextnode, asd);
  }
  nodes.push_back(node);
}

int main(void) {
  int n, m, a, b;
  cin >> n >> m;
  vector <vector <int>> asd(n);
  ffor(m) {
    cin >> a >> b;
    a--;b--;
    asd[a].push_back(b);
  }
  
  // topological sort
  vector <bool> visited(n);
  vector <int> nodes;
  for(int i = 0; i < n; i++) dfs(visited, nodes, i, asd);
  reverse(nodes.begin(), nodes.end());
  
  vector <int> dp(n); // length of longest cycle up to i
  for(int i = 0; i < n; i++) {
    int node = nodes[i];
    for (int nextnode: asd[node]) {
      dp[nextnode] = max(dp[nextnode], 1 + dp[node]);
    }
  }
  int ans = 0;
  for (auto e: dp) ans = max(ans, e);
  cout << ans << '\n';
}