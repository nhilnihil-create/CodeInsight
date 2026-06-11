#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  int n;
  cin >> n;
  
  vector<vector<char>> s(n, vector<char>(2 * n - 1));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> s.at(i).at(j);
      if (j < n - 1) s.at(i).at(j + n) = s.at(i).at(j);
    }
  }
  
  int ans = 0;
  for (int j = 0; j < n; j++) {
    bool flag = true;
    for (int ii = 0; ii < n; ii++) {
      for (int jj = 0; jj < n; jj++) {
        if (s.at(ii).at(j + jj) != s.at(jj).at(j + ii)) flag = false;
      }
    }
    if (flag) ans += n;
  }
  
  cout << ans << '\n';
}