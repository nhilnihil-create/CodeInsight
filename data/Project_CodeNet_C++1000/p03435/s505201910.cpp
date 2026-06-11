#include<bits/stdc++.h>
using namespace std;

int main(){
  int c[3][3],x[3],y[3];
  for(int i=1;i<=3;i++){
    for(int j=1;j<=3;j++){
      cin>>c[i][j];
    }
  }
  x[1]=0;
  for(int i=1;i<=3;i++){
    y[i]=c[1][i]-x[1];
    x[i]=c[i][1]-y[1];
  }
  bool at=true;
  for(int i=1;i<=3;i++){
    for(int j=1;j<=3;j++){
      if(x[i]+y[j]!=c[i][j]){
        at=false;
      }
    }
  }
  if(at) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
  
