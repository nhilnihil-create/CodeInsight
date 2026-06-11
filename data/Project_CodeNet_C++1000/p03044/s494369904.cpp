#include <bits/stdc++.h>
using namespace std;

void dfs(int x, int y, vector<int> &ans, int color, vector<vector<pair<int, int>>> &bridge) {
  ans.at(x) = color;
  for(int i = 0; i < bridge.at(x).size(); i++) {
    if(bridge.at(x).at(i).first == y) {
      continue;
    }
    if(bridge.at(x).at(i).second == 0) {
      dfs(bridge.at(x).at(i).first, x, ans, color, bridge);
    }
    else {
      dfs(bridge.at(x).at(i).first, x, ans, 1 - color, bridge);
    }
  }
}

int main() {
  int N;
  cin >> N;
  vector<vector<pair<int, int>>> bridge(N, vector<pair<int, int>>());
  for(int i = 0; i < N; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    bridge.at(u - 1).push_back(make_pair(v - 1, w % 2));
    bridge.at(v - 1).push_back(make_pair(u - 1, w % 2));
  }
  vector<int> ans(N, -1);
  dfs(0, -1, ans, 0, bridge);
  for(int i = 0; i < N; i++) {
    cout << ans.at(i) << endl;
  }
}