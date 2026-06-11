#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<vector<int>> c(3, vector<int>(3));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> c.at(i).at(j);
    }
  }
  
  vector<int> tmp = c.at(0);
  sort(tmp.begin(), tmp.end());
  int tmp_a = tmp.at(0);
  bool flag = false;
  for (int i = tmp_a; i >= 0; i--) {
    int tmp_b = c.at(0).at(0) - tmp_a;
    int tmp_bb = c.at(0).at(1) - tmp_a;
    int tmp_bbb = c.at(0).at(2) - tmp_a;
    if (c.at(1).at(0) - tmp_b == c.at(1).at(1) - tmp_bb) {
      if (c.at(1).at(0) - tmp_b == c.at(1).at(2) - tmp_bbb) {
        if (c.at(2).at(0) - tmp_b == c.at(2).at(1) - tmp_bb) {
          if (c.at(2).at(0) - tmp_b == c.at(2).at(2) - tmp_bbb) {
            flag = true;
            break;
          }
          if (flag) break;
        }
        if (flag) break;
      }
    if (flag) break;
    }
  }
  
  if (flag) cout << "Yes" << endl;
  else cout << "No" << endl;
}
