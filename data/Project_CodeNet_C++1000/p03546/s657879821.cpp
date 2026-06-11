#include<bits/stdc++.h>
using namespace std;
int main(void){
  int h,w,magic[10][10],ans=0;
  cin>>h>>w;
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      cin>>magic[i][j];
    }
  }
  for(int i=0;i<10;i++){
    for(int j=0;j<10;j++){
      for(int k=0;k<10;k++){
        magic[j][k]=min(magic[j][k],magic[j][i]+magic[i][k]);
      }
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      int a;
      cin>>a;
      if(a!=-1){
        ans+=magic[a][1];
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}