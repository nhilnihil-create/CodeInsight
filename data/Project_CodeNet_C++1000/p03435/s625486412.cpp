#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<vector<int>> c(3,vector<int>(3));
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++) cin >> c.at(i).at(j);
  }
  int x0; //x1, x2, y0, y1, y2;
  for(int i=0; i<=100; i++){
    x0=i;
    int y0=c.at(0).at(0)-x0;
    int y1=c.at(0).at(1)-x0;
    int y2=c.at(0).at(2)-x0;
    int x1=c.at(1).at(0)-y0;
    int x2=c.at(2).at(0)-y0;
    
    if(c.at(1).at(1) == x1+y1 && c.at(1).at(2) == x1+y2 && c.at(2).at(1) == x2+y1 && c.at(2).at(2) == x2+y2){
      cout << "Yes" << endl;
      return 0;
    }
  }
   cout << "No" << endl;
}