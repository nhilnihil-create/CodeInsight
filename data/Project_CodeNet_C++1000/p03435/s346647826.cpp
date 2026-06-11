#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<vector<int>> data(3, vector<int>(3));
 
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> data.at(i).at(j);
    }
  }
  int A = data.at(0).at(1) - data.at(0).at(0);
  int B = data.at(0).at(2) - data.at(0).at(0);
  int C = data.at(1).at(0) - data.at(0).at(0);
  int D = data.at(2).at(0) - data.at(0).at(0);
  
  if (data.at(1).at(1) - data.at(1).at(0) == A && data.at(1).at(2) - data.at(1).at(0) == B &&
     data.at(2).at(1) - data.at(2).at(0) == A && data.at(2).at(2) - data.at(2).at(0) == B &&
     data.at(1).at(1) - data.at(0).at(1) == C && data.at(2).at(1) - data.at(0).at(1) == D &&
     data.at(1).at(2) - data.at(0).at(2) == C && data.at(2).at(2) - data.at(0).at(2) == D ){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}