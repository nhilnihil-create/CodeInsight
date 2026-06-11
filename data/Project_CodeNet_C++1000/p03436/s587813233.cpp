#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define N_MAX (110)
#define INF 1001001001

int main() {
  int R, C;
  int white = 0;
  int black = 0;
  cin >> R >> C;

  vector<vector<char>> c(R, vector<char>(C));

  rep(i,R){
    rep(j,C){
      char tmp;
      cin >> tmp;
      c.at(i).at(j) = tmp;
      if(tmp == '.') white++;
      else black++;
    }
  }
  
  int sy = 0, sx = 0;
  int gy = R-1, gx = C-1;
  queue<pair<int, int>> q;
  pair<int, int> p_start(sy, sx);
  pair<int, int> p_end(gy, gx);
  vector<vector<int>> dist(R, vector<int>(C, INF));
  vector<vector<bool>> seen(R,vector<bool>(C, false));

  vector<int> dy = {-1, 0, 1, 0};
  vector<int> dx = {0, 1, 0, -1};

  dist.at(sy).at(sx) = 0;

  q.push(p_start);
  while(!q.empty()){
    pair<int, int> p;
    p = q.front(); q.pop();

    int y = p.first;
    int x = p.second;

    rep(i,4){
      int h = y + dy.at(i);
      int w = x + dx.at(i);

      if(w < 0 || w >= C) continue;
      if(h < 0 || h >= R) continue;
      if(c.at(h).at(w) == '#') continue;
      if(dist.at(h).at(w) != INF) continue;

      pair<int, int> p(h, w);
      q.push(p);
      dist.at(h).at(w) = min(dist.at(h).at(w), dist.at(y).at(x) + 1);
    }   
  }

  if(dist.at(gy).at(gx) != INF){
  	cout << white-dist.at(gy).at(gx)-1 << endl;
  }
  else{
    cout << -1 << endl;
  }
  return 0;
}