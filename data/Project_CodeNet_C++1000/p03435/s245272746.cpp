#include <bits/stdc++.h>
using namespace std;
int a[4][4],b[4][4],c[4][4];
int main(){
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      cin>>a[i][j];
    }
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<2;j++){
      b[i][j]=a[i][j+1]-a[i][j];
    }
  }
  for(int i=0;i<2;i++){
    for(int j=0;j<3;j++){
      c[i][j]=a[i+1][j]-a[i][j];
    }
  }
  for(int i=0;i<2;i++){
    for(int j=0;j<3;j++){
      if(b[i][j]!=b[i+1][j]){
        //cout<<b[i][j]<<" "<<b[i+1][j]<<endl;
        cout<<"No"<<endl;
        return 0;
      }
    }
  }
  for(int i=0;i<3;i++){
    for(int j=0;j<2;j++){
      if(c[i][j]!=c[i][j+1]){
        //cout<<i<<" "<<j<<" "<<c[i][j]<<" "<<c[i][j+1]<<endl;
        cout<<"No"<<endl;
        return 0;
      }
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}
