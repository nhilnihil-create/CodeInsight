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
    if(s[i][j]=='.'){
      s[i][j]='0';
      for(int x=-1;x<=1;x++)for(int y=-1;y<=1;y++){
        int dx=i+x,dy=j+y;
        if(0<=dx&&dx<h&&0<=dy&&dy<w&&s[dx][dy]=='#'){
          s[i][j]++;
        }
      }
    }
  }
    rep(i,h)rep(j,w){
      cout<<s[i][j];
      if(j==w-1)cout<<endl;
    }
}