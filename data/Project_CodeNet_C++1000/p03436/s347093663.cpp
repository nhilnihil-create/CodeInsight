#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int h,w,bc = 0;
  cin >> h >> w;
  vector<string>data(h);
  rep(i,0,h){
    cin >> data[i];
    rep(j,0,w) if(data[i][j] == '#') bc++;
  }
  vector<vector<int>>dist(h,vector<int>(w,-1));
  dist[0][0] = 0;
  queue<P>que;
  que.push(P(0,0));
  while(!que.empty()){
    int x = que.front().first,y = que.front().second;
    que.pop();
    if(x > 0){
      if(data[x-1][y] == '.' && dist[x-1][y] == -1){
        que.push(P(x-1,y));
        dist[x-1][y] = dist[x][y]+1;
      }
    }
    if(x < h-1){
      if(data[x+1][y] == '.' && dist[x+1][y] == -1){
        que.push(P(x+1,y));
        dist[x+1][y] = dist[x][y]+1;
      }
    }
    if(y > 0){
      if(data[x][y-1] == '.' && dist[x][y-1] == -1){
        que.push(P(x,y-1));
        dist[x][y-1] = dist[x][y]+1;
      }
    }
    if(y < w-1){
      if(data[x][y+1] == '.' && dist[x][y+1] == -1){
        que.push(P(x,y+1));
        dist[x][y+1] = dist[x][y]+1;
      }
    }
  }
  if(dist[h-1][w-1] == -1) cout << -1 << endl;
  else cout << h*w-dist[h-1][w-1]-1-bc << endl;
}