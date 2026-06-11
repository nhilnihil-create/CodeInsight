#include<bits/stdc++.h>
using namespace std;
int main(){
  char s[3][3];
  int i,j;
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
     cin >> s[i][j];
    }
  }
  for(i=0;i<3;i++){
    for(j=0;j<3;j++){
      if(i==j){
        cout<< s[i][j];
      }
    }
  }
}
  