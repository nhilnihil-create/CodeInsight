#include <bits/stdc++.h>
using namespace std;

int main(){

vector<vector<int>> c(3,vector<int>(3));
for(int i=0;i<3;i++){
 for(int j=0;j<3;j++){
 cin >> c[i][j]; 
 }
}
 bool flag = false;
 for(int j=0;j<2;j++){
if(c[0][j]-c[0][j+1]==c[1][j]-c[1][j+1] && c[1][j]-c[1][j+1]==c[2][j]-c[2][j+1]){
flag=true;
}else {
  flag =false;
  break;
}
 }
if(flag) cout << "Yes" << endl;
   else cout << "No"    << endl;
}