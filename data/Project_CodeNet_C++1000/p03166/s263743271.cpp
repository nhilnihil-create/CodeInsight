#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG

int func(int x, vector<vector<int>> &graph, vector<int> &flag, vector<int> &dp) {
  if (flag[x])
    return dp[x];
  
  // flag[x] == 1 bugの原因
  flag[x] = 1;
  int check = 0;
  for (auto i : graph[x]) {
    check = max(check, func(i, graph, flag, dp) + 1);
  }
  dp[x] = check;
  return dp[x];
}

int main() {  
  
  int N, M;
  cin >> N >> M;
  vector<int> flag(N + 1, 0);
  vector<int> dp(N + 1, 0);
  vector<vector<int>> graph(N + 1);
  int x, y;
  for (int i = 0; i < M; i++) {
      cin >> x >> y;
      graph[x].push_back(y);
  }
  // 各nodeをdfsで探索
  int ans = 0;
  for (int i = 1; i < N + 1; i++) {
      ans = max(ans, func(i, graph, flag, dp));
  }
  cout << ans << endl;
}