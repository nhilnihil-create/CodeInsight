#include <bits/stdc++.h>
using namespace std;
  
int main() {
  
  int c[3][3];//3×3の配列
  
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cin >> c[i][j];
    }
  }
  
  if(
    (abs(c[0][0]-c[0][1])==abs(c[1][0]-c[1][1]))&&
    (abs(c[1][0]-c[1][1])==abs(c[2][0]-c[2][1])) && 
    
    (abs(c[0][1]-c[0][2])==abs(c[1][1]-c[1][2])) &&
    (abs(c[1][1]-c[1][2])==abs(c[2][1]-c[2][2])) && 
    
     (abs(c[1][0]-c[0][0])==abs(c[1][1]-c[0][1]))&&
    (abs(c[1][1]-c[0][1])==abs(c[1][2]-c[0][2])) && 
    
     (abs(c[2][0]-c[1][0])==abs(c[2][1]-c[1][1])) &&
    (abs(c[2][1]-c[1][1])==abs(c[2][2]-c[1][2]))
  ){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
    
}