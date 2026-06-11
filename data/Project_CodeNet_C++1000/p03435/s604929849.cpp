#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<vector<int>> c(3, vector<int>(3)); 
  int a[3], b[3];
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> c[i][j];
    }
  }
  a[0] = 0;
  for (int i = 0; i < 3; i++) b[i] =  c[0][i] - a[0]; 
  for (int i = 0; i < 3; i++) a[i] =  c[i][0] - b[0]; 

  bool jug = true;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (a[i] + b[j] != c[i][j]) jug = false; 
    }
  }
  if (jug) cout << "Yes" << endl;
  else cout << "No" <<endl;
}