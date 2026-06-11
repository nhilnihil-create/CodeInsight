#include <bits/stdc++.h>
using namespace std;

main(void){
  vector<vector<int>> c(3,vector<int>(3));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin >> c.at(i).at(j);
    }
  }
  int x[3],y[3];
  for(int i=0;i<=100;i++){
    x[0]=i;
    for(int j=0;j<3;j++) y[j]=c[0][j]-x[0];
    for(int j=0;j<3;j++) x[j]=c[j][0]-y[0];
    for(int j=0;j<3;j++){
      for(int k=0;k<3;k++){
        if(x[j]+y[k]!=c[j][k]){
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }
  cout << "Yes" <<endl;
}