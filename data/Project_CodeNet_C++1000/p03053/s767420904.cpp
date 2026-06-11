#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int dx[4] = { 1, 0, -1, 0 };
const int dy[4] = { 0, 1, 0, -1 };

int main() {
  int h,w;
  cin>>h>>w;
  int ans=0;
  vector<string> field(h);
  int vec[h][w];
  for(int i=0;i<h;i++){
    cin>>field[i];
    for(int j=0;j<w;j++){
      if(field[i][j]=='.'){
        vec[i][j]=3000;
      }
      else{
        vec[i][j]=0;
      }
    }
  }
  for(int a=0;a<5;a++){
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
        for(int k=0;k<4;k++){
          int m=i+dx[k];
          int n=j+dy[k];
          if(m<0||m>=h||n<0||n>=w)continue;
          vec[i][j]=min(vec[i][j],vec[m][n]+1);
        }
      }
    }
    for(int i=0;i<h;i++){
      for(int j=w-1;j>=0;j--){
        for(int k=0;k<4;k++){
          int m=i+dx[k];
          int n=j+dy[k];
          if(m<0||m>=h||n<0||n>=w)continue;
          vec[i][j]=min(vec[i][j],vec[m][n]+1);
        }
      }
    }
    for(int i=h-1;i>=0;i--){
      for(int j=0;j<w;j++){
        for(int k=0;k<4;k++){
          int m=i+dx[k];
          int n=j+dy[k];
          if(m<0||m>=h||n<0||n>=w)continue;
          vec[i][j]=min(vec[i][j],vec[m][n]+1);
        }
      }
    }
    for(int i=h-1;i>=0;i--){
      for(int j=w-1;j>=0;j--){
        for(int k=0;k<4;k++){
          int m=i+dx[k];
          int n=j+dy[k];
          if(m<0||m>=h||n<0||n>=w)continue;
          vec[i][j]=min(vec[i][j],vec[m][n]+1);
        }
      }
    }
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      ans=max(vec[i][j],ans);
    }
  }
  cout<<ans<<endl;
}