#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int,int>;
using T = tuple<string,int,int>;
const ll INF = 1LL<<60;
const int ny[4] = {-1,1,0,0}, nx[4] = {0,0,-1,1};

int main(){
  int H,W; cin >> H >> W;
  char g[H][W];
  queue<P> q;
  for(int i = 0; i < H; i++){
    for(int j = 0; j < W; j++){
      cin >> g[i][j];
      if(g[i][j] == '#') q.push(P(i,j));
    }
  }
  if(H == 1 && W == 1){
    cout << 0 << endl;
    return 0;
  }
  int ans = 0;
  int a = q.size(), b = 0;
  while(!q.empty()){
    P p = q.front(); q.pop(); a--;
    int dy = p.first, dx = p.second;
    for(int i = 0; i < 4; i++){
      int y = dy+ny[i], x = dx+nx[i];
      if(0 > y || y >= H || 0 > x || x >= W) continue;
      if(g[y][x] == '#') continue;
      g[y][x] = '#';
      q.push(P(y,x));
      b++;
    }
    if(a == 0 && b != 0){
      ans++;
      swap(a,b);
    }
  }
  cout << ans << endl;
  return 0;
}
