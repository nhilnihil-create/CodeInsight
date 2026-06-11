#include <bits/stdc++.h>
using namespace std;

int main() {
  
  vector<vector<int>> c(3,vector<int>(3));
  for ( int i = 0; i < 3; i++){
    for ( int j = 0; j < 3; j++){
      cin >> c[i][j];
    }
  }
  
  for ( int i = 0; i < 3; i++){
    c[i][1] -= c[i][0]; c[i][2] -= c[i][0]; c[i][0] = 0;
  }
  for ( int j = 0; j < 3; j++){
    if ( !(c[0][j] == c[1][j] && c[1][j] == c[2][j]) ){
      cout << "No" << endl;
      return 0;
    }
  }
  
  cout << "Yes" << endl;
  return 0;
   
}