#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n, C;
  cin >> n >> C;
  
  vector<vector<int>> x(n, vector<int>(3));
  for (int i = 0; i < n; i++) {
    cin >> x.at(i).at(1) >> x.at(i).at(2) >> x.at(i).at(0);
  }
  
  vector<int> z(200002);
  for (int i = 1; i <= C; i++) {
    vector<int> y(200002);
    for (int j = 0; j < n; j++) {
      if (x.at(j).at(0) == i) {
        y.at(x.at(j).at(1) * 2 - 1)++;
        y.at(x.at(j).at(2) * 2)--;
      }
    }
    for (int j = 0; j < 200002; j++) {
      if (j) y.at(j) += y.at(j - 1);
      if (y.at(j) > 0) z.at(j)++;
    }
  }
  
  int ans = 0;
  for (int i = 0; i < 200002; i++) ans = max(ans, z.at(i));
  cout << ans << '\n';
}