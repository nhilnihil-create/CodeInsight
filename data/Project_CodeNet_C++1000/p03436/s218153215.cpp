#include <bits/stdc++.h>
using namespace std;
using P = pair<int,int>;

int main(){
  int h, w;
  cin >> h >> w;
  vector<string> m(h);
  for(int i=0; i<h; ++i) cin >> m[i];
  queue<P> que;
  que.push(make_pair(0,0));
  vector<vector<int>> dis(h,vector<int>(w,-1));
  dis[0][0] = 1;
  while(!que.empty()){
    int x, y;
    tie(x,y) = que.front();
    que.pop();
    if(x>0 && dis[x-1][y] == -1 && m[x-1][y] == '.'){
      dis[x-1][y] = dis[x][y] +1;
      que.push(make_pair(x-1,y));
    }
    if(y>0 && dis[x][y-1] == -1 && m[x][y-1] == '.'){
      dis[x][y-1] = dis[x][y] +1;
      que.push(make_pair(x,y-1));
    }
    if(x<h-1 && dis[x+1][y] == -1 && m[x+1][y] == '.'){
      dis[x+1][y] = dis[x][y] +1;
      que.push(make_pair(x+1,y));
    }
    if(y<w-1 && dis[x][y+1] == -1 && m[x][y+1] == '.'){
      dis[x][y+1] = dis[x][y] +1;
      que.push(make_pair(x,y+1));
    }
  }
  if(m[0][0] == '#' || dis[h-1][w-1] == -1){
    cout << -1 << endl;
    return 0;
  }
  int ans = 0;
  for(int i=0; i<h; ++i) for(int j=0; j<w; ++j){
    if(m[i][j] == '.') ++ans;
  }
  ans -= dis[h-1][w-1];
  cout << ans << endl;
}