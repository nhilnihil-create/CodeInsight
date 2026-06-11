#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int h,w;
  cin >> h >> w;

  vector<vector<char>> grid(h, vector<char>(w));
  rep(i,h)rep(j,w) cin >> grid.at(i).at(j);
  
  vector<vector<int>> delta =  {{-1,0},{0,-1},{1,0},{0,1}};
  
  rep(i,h)rep(j,w){
    if(grid.at(i).at(j)=='.') continue;
    bool paint =  false;
    rep(k,4){
      int dx = delta.at(k).at(0);
      int dy = delta.at(k).at(1);
      if(i+dx>=0&&i+dx<h&&j+dy>=0&&j+dy<w&&grid.at(i+dx).at(j+dy)=='#') paint=true;
    }
    if(!paint) {cout << "No"; return 0;}
  }

  cout << "Yes";
  
}