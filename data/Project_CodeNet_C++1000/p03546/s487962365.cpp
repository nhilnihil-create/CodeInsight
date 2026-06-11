#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> cost(10,vector<int>(10));
  for (auto &v : cost) {
    for (int &e : v) cin >> e;
  }
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < 10; k++) {
        cost[j][k] = min (cost[j][k], cost[j][i]+cost[i][k]);
      }
    }
  }
  vector<int> lowest(10);
  for (int i = 0; i < 10; i++) lowest[i] = cost[i][1];
  
  int ans = 0;
  for (int i = 0; i < H*W; i++) {
    int n; cin >> n;
    if (n < 0) continue;
    ans += lowest[n];
  }
  cout << ans << endl;
}