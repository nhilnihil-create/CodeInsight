#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<vector<char>> C(2, vector<char>(3));
  for (int i=0; i<2; i++) {
    for (int j=0; j<3; j++) {
      cin >> C[i][j];
    }
  }
  
  string ans = "YES";
  for (int i=0; i<3; i++) {
    if (C[0][i]!=C[1][2-i]) {ans="NO";}
  }
  cout << ans << endl;
}
