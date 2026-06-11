#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,w;cin>>h>>w;
  vector<vector<char>> in(h,vector<char>(w));
  vector<vector<char>> out(h,vector<char>(w));
  for(int i=0;i<h;++i)for(int j=0;j<w;++j)cin>>in[i][j];
  for(int i=0;i<h;++i)for(int j=0;j<w;++j)out[i][j]='.';
  
  for(int i=0;i<h;++i){
    for(int j=0;j<w;++j){
      bool r=false;
      if(in[i][j]=='#'){
        if(i>0)if(in[i-1][j]=='#')r=true;
        if(i<h-1)if(in[i+1][j]=='#')r=true;
        if(j>0)if(in[i][j-1]=='#')r=true;
        if(j<w-1)if(in[i][j+1]=='#')r=true;
        if(r)out[i][j]='#';
      }
    }
  }
  for(int i=0;i<h;++i) for(int j=0;j<w;++j)if(in[i][j]!=out[i][j])return cout<<"No",0;
  cout<<"Yes";
}