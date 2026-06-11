#include<bits/stdc++.h>
using namespace std;

int main() {
  vector<vector<int>> c(3, vector<int>(3));

  int tmp;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> tmp;
      c.at(i).at(j) = tmp;
    }
  }

  int a1Upper = 100;
  for (int i = 0; i < 3; i++) a1Upper = min(a1Upper, c.at(0).at(i));
  string ans = "No";
  int b1, b2, b3, a2, a3;
  for (int a1 = 0; a1 <= a1Upper; a1++) {
    b1 = c.at(0).at(0) - a1;
    b2 = c.at(0).at(1) - a1;
    b3 = c.at(0).at(2) - a1;
    a2 = c.at(1).at(0) - b1;
    a3 = c.at(2).at(0) - b1;
    if (b1 < 0 || b2 < 0 || b3 < 0 || a2 < 0 || a3 < 0) {
      continue;
    }
    if ((a2 != c.at(1).at(1) - b2) || (a2 != c.at(1).at(2) - b3)) {
      continue;
    }
    if ((a3 != c.at(2).at(1) - b2) || (a3 != c.at(2).at(2) - b3)) {
      continue;
    }
    ans = "Yes";
    break;
  }
  
  cout << ans << endl;
}
