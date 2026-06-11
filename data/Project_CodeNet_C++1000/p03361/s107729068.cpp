#include<bits/stdc++.h>
using namespace std;
int main(void){
  bool tf=true;
  int h,w;
  cin>>h>>w;
  string s[100];
  for(int i=0;i<h;i++){
    cin>>s[i];
  }
  const int dx[4]={1,0,-1,0};
  const int dy[4]={0,-1,0,1};
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='.'){
        continue;
      }
      bool tf2=false;
      for(int k=0;k<4;k++){
        int n1=i+dx[k];
        int n2=j+dy[k];
        if(n1<0 || h<=n1){
          continue;
        }
        if(n2<0 || w<=n2){
          continue;
        }
        if(s[n1][n2]=='#'){
          tf2=true;
        }
      }
      if(tf2==false){
        tf=false;
        goto finish;
      }
    }
  }
  if(tf==true){
    cout<<"Yes"<<endl;
  }
  finish:
  if(tf==false){
    cout<<"No"<<endl;
  }
  return 0;
}