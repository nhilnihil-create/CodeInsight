#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)
int main() {
  int n;
  cin >> n;
  vector<vector<int>> edge(n);
  rep(i, n) {
    rep(j, n) {
      if(i == j) continue;
      if(n % 2 == 0 && i + j == n - 1) continue;
      if(n % 2 == 1 && i + j == n - 2) continue;
      edge[i].emplace_back(j);
    }
  }
  if(n % 2 == 0) cout << n * (n - 2) / 2 << endl;
  else cout << (n - 1) * (n - 3) / 2 + n - 1 << endl;
  rep(i, n) {
    for(auto& node : edge[i]) {
      if(i > node) continue;
      cout << i+1 << ' ' << node + 1 << endl;
    }
  }
  return 0;
}
