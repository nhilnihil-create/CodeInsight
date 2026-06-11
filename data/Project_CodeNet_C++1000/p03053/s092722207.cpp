#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int h,w;
  cin >> h >> w;

  queue<P> q;
  vector<int> dx = {-1, 0, 1, 0};
  vector<int> dy = { 0, 1, 0,-1};
  //vector<vector<vector<P>>> to(h,vector<P>(w,vector<P>(0));
  //vector<vector<P>> to[100005][100005];
  P to[h][w][4];

  vector<string> a(h);
  rep(i,h){
    cin >> a[i];
    rep(j,w){
      if(a[i][j]=='#'){
        q.push(make_pair(i,j));
      }
      rep(k,4){
        if(i+dy[k]>=0&&i+dy[k]<h&&j+dx[k]>=0&&j+dx[k]<w){
          to[i][j][k] = make_pair(i+dy[k],j+dx[k]);
        }
        else{
          to[i][j][k] = make_pair(-1,-1);
        }
      }
    }
  }

  vector<vector<int>> dist(h,vector<int>(w,0));
  int ans = 0;
  while(!q.empty()){
    P v = q.front();
    q.pop();
    int yv = v.first;
    int xv = v.second;
    for(auto p : to[yv][xv]){
      int yu = p.first;
      int xu = p.second;
      if(xu==-1||yu==-1) continue;
      if(a[yu][xu]=='#') continue;
      a[yu][xu] = '#';
      dist[yu][xu] = dist[yv][xv] + 1;
      if(ans<dist[yu][xu]) ans = dist[yu][xu];
      q.push(make_pair(yu,xu));
    }
  }

  cout << ans << endl;

  return 0;
}
