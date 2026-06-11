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
  x[0]=0;
  for(int i=0;i<3;i++) y[i]=c[0][i]-x[0];
  for(int i=0;i<3;i++) x[i]=c[i][0]-y[0];
  bool good=true;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      if(c[i][j]!=x[i]+y[j]) good=false;
    }
  }
  if(good) cout << "Yes";
  else cout << "No";
}