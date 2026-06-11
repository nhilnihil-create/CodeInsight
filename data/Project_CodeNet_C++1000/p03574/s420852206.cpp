#include <bits/stdc++.h>
using namespace std;


int main() {
  int H, W;
  cin >> H >> W;
  
  vector<string> S(H);
  vector<vector<int>> A(H+2, vector<int>(W+2,0));
  for (int i=0; i<H; i++) {
  	cin >> S.at(i);
    for (int j=0; j<W; j++) {
      if (S.at(i).at(j)=='#') {
        A.at(i).at(j) += 1;
        A.at(i).at(j+1) += 1;
        A.at(i).at(j+2) += 1;
        A.at(i+1).at(j) += 1;
        A.at(i+1).at(j+1) += 1;
        A.at(i+1).at(j+2) += 1;
        A.at(i+2).at(j) += 1;
        A.at(i+2).at(j+1) += 1;
        A.at(i+2).at(j+2) += 1;
      }
    }
  }
  
  for (int i=0; i<H; i++) {
    for (int j=0; j<W; j++) {
      if (S.at(i).at(j)=='#') cout << "#";
      else cout << A.at(i+1).at(j+1);
    }
    cout << endl;
  }    
  

  return 0;
}
