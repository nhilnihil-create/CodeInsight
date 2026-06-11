#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int N;
list<int> E[100005];
int visited[100005];
vector<int> dfs_out;

void dfs(int u) {
  visited[u] = true;
  for (auto it = E[u].begin(); it != E[u].end(); it++) {
    if (!visited[*it]) {
      dfs(*it);
    }
  }
  dfs_out.push_back(u);
}

int main() {
  int M; cin >> N >> M;
  int x, y;
  for (int i = 0; i < M; i++) {
    cin >> x >> y; x--; y--;
    E[x].push_back(y);
  }
  for (int i = 0; i < N; i++) {
    if (!visited[i]) dfs(i);
  }
  int dp[N]; for (int i = 0; i < N; i++) dp[i] = 0;
  for (int i = 0; i < N; i++) {
    int u = dfs_out[i];
    for (auto it = E[u].begin(); it != E[u].end(); it++) {
      dp[u] = max(dp[u], dp[*it] + 1);
    }
  }
  cout << *max_element(dp, dp+N) << endl;
}