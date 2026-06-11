#include <bits/stdc++.h>
using namespace std;
char masu[60][60];
int kekka[60][60];
int main() {
  int h,w;
  cin>>h>>w;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>masu[i][j];
      kekka[i][j]=0;
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(masu[i][j]=='.'&&masu[i][j+1]=='.'&&j+1<w){
        masu[i][j]='#';
        masu[i][j+1]='#';
      }
      if(masu[i+1][j]=='#' && i+1<h ){
        kekka[i][j]=1;
      }
      if(masu[i][j+1]=='#' && j+1<w){
        kekka[i][j]=1;
      }
      if(masu[i-1][j]=='#' && i-1>=0){
        kekka[i][j]=1;
      }
      if(masu[i][j-1]=='#' && j-1>=0){
        kekka[i][j]=1;
      }
    }
  }  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(kekka[i][j]!=1){
        cout<<"No"<<endl;
        return 0;
      }
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}