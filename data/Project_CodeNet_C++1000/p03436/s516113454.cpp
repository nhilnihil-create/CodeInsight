#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main(){
  int r,c,ans;
  ans = 0;
  cin >> r >> c;
  int sx,sy,gx,gy;
  sx = 1;
  sy = 1;
  gx = c;
  gy = r;
  map<int,string> map;
  vector<vector<int>> v(r+2,vector<int>(c+2,0));
  string wall = "";
  rep(i,c+2) wall+="#";
  map[0] = wall;
  rep(i,r){
    string s;
    cin >> s;
    rep(j,c){
      if(s.at(j)=='.') ans++;
    }
    s = "#" + s + "#";
    map[i+1] = s;
  }
  map[r+1] = wall;
  int turn = -1;
  int nx,ny;
  int mkr=0;
  nx=sx;
  ny=sy;
  vector<int> x = {1,0,-1,0};
  std::vector<int> y = {0,1,0,-1};
  queue<P> q;
  set<int> st;
  P p(nx,ny);
  q.push(p);
  while(true){
    turn+=1;
    queue<P> Q;
    while(q.size()>0){
      nx = q.front().first;
      ny = q.front().second;
      if(nx == gx && ny == gy){
        mkr=1;
        break;
      }
      q.pop();
      for(int i=0; i<4; i++){
        if(map[ny+y[i]].at(nx+x[i])=='.' && v[ny+y[i]][nx+x[i]]==0){
          P p(nx+x[i],ny+y[i]);
          v[ny+y[i]][nx+x[i]] = 1;
          Q.push(p);
        }
      }
    }
    if(mkr==1){
      break;
    }
    else if(Q.size()==0){
      ans=turn;
      break;
    }
    q=Q;
  }
  cout << ans - turn - 1 << endl;
}