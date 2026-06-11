#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int h,w;cin>>h>>w;
  vector<vector<char>> s(h,vector<char>(w));
  rep(i,h)rep(j,w)cin>>s[i][j];
  rep(i,h)rep(j,w){
    if(s[i][j]=='#')continue;
    s[i][j]='0';
    for(int dx=-1;dx<=1;dx++){
      for(int dy=-1;dy<=1;dy++){
        int nx=i+dx,ny=j+dy;
        if(0<=nx&&nx<h&&0<=ny&&ny<w){
          if(s[nx][ny]=='#')s[i][j]++;
        }
      }
    }
  }
  rep(i,h)rep(j,w){
    cout<<s[i][j];
    if(j==w-1)cout<<endl;
  }
}