#include <bits/stdc++.h>
using namespace std;
 
int main() {
  vector<vector<int>> c(3,vector<int>(3));
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++) cin >> c.at(i).at(j);
  }
  int x0 ,x1, y0, y1;
    x0=c.at(0).at(0) - c.at(0).at(1) ;
    x1=c.at(0).at(1) - c.at(0).at(2) ;
    y0=c.at(0).at(0) - c.at(1).at(0) ;
    y1=c.at(1).at(0) - c.at(2).at(0) ;   
    
    if(c.at(1).at(0) - c.at(1).at(1) == x0 &&\
       c.at(1).at(1) - c.at(1).at(2) == x1 &&\
       c.at(2).at(0) - c.at(2).at(1) == x0 &&\
       c.at(2).at(1) - c.at(2).at(2) == x1 &&\
       c.at(0).at(1) - c.at(1).at(1) == y0 &&\
       c.at(1).at(1) - c.at(2).at(1) == y1 &&\
       c.at(0).at(2) - c.at(1).at(2) == y0 &&\
       c.at(1).at(2) - c.at(2).at(2) == y1){
     cout << "Yes" << endl;
    }
    else cout << "No" << endl;
  return 0;
}