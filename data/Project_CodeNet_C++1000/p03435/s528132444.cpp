#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<vector<int>> c(3,vector<int>(3));//多次元配列の確認
  string answer = "Yes";
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> c.at(i).at(j);//添え字のずれに注意
    }
  }
  vector<int> a(3);
  vector<int> b(3);
  for (int i = 0; i <= c[0][0]; i++) {
    a[0] = i;
    b[0] = c[0][0] - a[0];
    b[1] = c[0][1] - a[0];
    b[2] = c[0][2] - a[0];
    a[1] = c[1][0] - b[0];
    a[2] = c[2][0] - b[0];
    if (c[1][1] != a[1] + b[1] || c[1][2] != a[1] + b[2] || c[2][1] != a[2] + b[1] || c[2][2] != a[2] + b[2]) {
      answer = "No";
      break;
    }
  }
  cout << answer;
}