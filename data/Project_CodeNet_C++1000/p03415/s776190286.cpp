#include<bits/stdc++.h>
using namespace std;
int main(){
char mat[3][3];
  for(auto i=0; i<3; i++){
  	for(auto j=0; j<3; j++) cin>>mat[i][j];
  }
  
  for(auto i=0; i<3; i++){
  	for(auto j=0; j<3; j++) if(i == j) cout<<mat[i][j];
  }
  return 0;
}
