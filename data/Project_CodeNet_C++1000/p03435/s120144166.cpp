#include<bits/stdc++.h>
using namespace std;

int main(){
  int c[3][3];
  int a[3];
  int b[3];
  string check="No";
  for(int i=0; i<3; i++){
    for(int j=0; j<3; j++){
      cin >> c[i][j];
    }
  }
  
  for(int i=0;i<=c[0][0];i++){
    a[0]=i;
    for(int j=0;j<3;j++){
      b[j]=c[0][j] - a[0];
    }
    a[1]=c[1][0] -b[0];
    a[2]=c[2][0] -b[0];
    if(c[1][1]==a[1]+b[1]&c[1][2]==a[1]+b[2]&c[2][1]==a[2]+b[1]&c[2][2]==a[2]+b[2]){
      check ="Yes";
    }
  }
  cout << check <<endl;
}
    
    