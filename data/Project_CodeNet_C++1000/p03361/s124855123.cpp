#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  int h,w;
  cin >> h >> w;
  char c[h][w];
  rep(i,h){
    rep(j,w){
      cin >> c[i][j];
    }
  }
  string ans="Yes";
  int x[4]={1,0,-1,0};
  int y[4]={0,1,0,-1};
  rep(i,h){
    rep(j,w){
      if(c[i][j]=='#'){
        bool is=false;
        rep(k,4){
          int xx=x[k]+i;
          int yy=y[k]+j;
          if(xx>=h || xx<0 || yy>=w || yy<0){
            continue;
          }
          if(c[xx][yy]=='#'){
            is=true;
          }
        }
        if(!is){
          ans="No";
        }
      }
    }
  }
   cout << ans;
}
    
    
      