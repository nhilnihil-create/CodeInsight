#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H >> W;
  vector<vector<char>> c(52,vector<char> (52));
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      cin >> c.at(i).at(j);
    }
  }
  bool can = true;
  for(int i=1;i<=H;i++){
    for(int j=1;j<=W;j++){
      if(c.at(i).at(j)=='#'&&(c.at(i).at(j-1)!='#'&&c.at(i).at(j+1)!='#'&&c.at(i-1).at(j)!='#'&&c.at(i+1).at(j)!='#')){
        can = false;
      }
    }
  }
  if(can) cout << "Yes" << endl;
  else cout << "No" << endl;  
}