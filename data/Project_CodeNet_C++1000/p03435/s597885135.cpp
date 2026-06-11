#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
  int c[3][3];
  rep(i,3)rep(j,3)cin>>c[i][j];
  int cross=0,all=0;
  rep(i,3)cross+=c[i][i];
  rep(i,3)rep(j,3)all+=c[i][j];
  
  if(3*cross==all)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  
  return 0;
}