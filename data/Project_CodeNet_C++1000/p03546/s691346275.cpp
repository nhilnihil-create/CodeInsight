#include<bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  vector<vector<int>> c(10,vector<int>(10));
  for(int i=0;i<10;i++)
    for(int j=0;j<10;j++)
      cin>>c.at(i).at(j);
  vector<vector<int>> m=c;
  for(int x=0;x<10;x++)
    for(int i=0;i<10;i++)
      for(int j=0;j<10;j++)
        m[i][j]=min(m[i][j],m[i][x]+m[x][j]);
  int s=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      int a;
      cin>>a;
      s+=(a!=-1?m[a][1]:0);
    }
  }
  cout<<s<<endl;
}