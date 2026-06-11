#include<bits/stdc++.h>
using namespace std;

int main(){
  int c[3][3];
  for(int i=0; i<3; i++) {
    for(int j=0; j<3; j++) {
      cin >> c[i][j];
    }
  }
  
  int x,y;
  bool chk = true;
  for(int i=0; i<3; i++) {
    if(i==0) {
      x = c[i][1]-c[i][0];
      y = c[i][2]-c[i][1];    
    }
    if(i>0) {
      if(x!=c[i][1]-c[i][0]) chk = false;
      if(y!=c[i][2]-c[i][1]) chk = false;    
    }
  }
  
  cout << ( chk ? "Yes" : "No" ) << endl; 
  return 0;
}