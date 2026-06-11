#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<vector<int>> c(3, vector<int>(3));
  for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
      cin >> c.at(i).at(j);
    }
  }
  
  for (int a1 = 0; a1 <= 100; a1++){
    int b1 = c.at(0).at(0) - a1;
    int b2 = c.at(0).at(1) - a1;
    int b3 = c.at(0).at(2) - a1;
    int a2 = c.at(1).at(0) - b1;
    int a3 = c.at(2).at(0) - b1;
    if (c.at(1).at(1) == a2 + b2 && c.at(1).at(2) == a2 + b3
        && c.at(2).at(1) == a3 + b2 && c.at(2).at(2) == a3 + b3){
      cout << "Yes" << endl;
      return 0;
    }
  }
  
  cout << "No" << endl;
  return 0;
}