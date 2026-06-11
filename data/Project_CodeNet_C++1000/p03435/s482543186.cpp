#include <bits/stdc++.h>
using namespace std;

int main() {
  int max = 0;
  vector<vector<int>> v(3, vector<int>(3));
  for(int i=0; i<3; i++) for(int j=0; j<3; j++) cin >> v[i][j];
  
  bool check = false;
  if(v[0][0]-v[1][0]!=v[0][1]-v[1][1] || v[0][1]-v[1][1]!=v[0][2]-v[1][2]) check = true;
  if(v[1][0]-v[2][0]!=v[1][1]-v[2][1] || v[1][1]-v[2][1]!=v[1][2]-v[2][2]) check = true;
  if(v[0][0]-v[0][1]!=v[1][0]-v[1][1] || v[1][0]-v[1][1]!=v[2][0]-v[2][1]) check = true;
  if(v[0][1]-v[0][2]!=v[1][1]-v[1][2] || v[1][1]-v[1][2]!=v[2][1]-v[2][2]) check = true;
  
  if(check) cout << "No" << endl;
  else cout << "Yes" << endl;
  return 0;
}