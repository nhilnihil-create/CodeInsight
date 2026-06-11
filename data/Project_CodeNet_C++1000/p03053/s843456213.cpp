#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

int main()
{
  int h, w;
  cin >> h >> w;
  vector<vector<char>> grid(h, vector<char>(w));
  vector<vector<int>> dist(h, vector<int>(w, -1));
  
  queue<P> q;
  rep(i, h) rep(j, w)
  {
    cin >> grid[i][j];
    if(grid[i][j] == '#')
    {
      q.push(P(i, j));
      dist[i][j] = 0;
    }
  }
  
  vector<int> dy = {-1, 0, 1, 0}, dx = {0, -1, 0, 1};
  
  while(q.size())
  {
    P p = q.front();
    q.pop();
    
    rep(i, 4)
    {
      int ny = p.first + dy[i], nx = p.second + dx[i];
      if(ny >= 0 && ny < h && nx >= 0 && nx < w && dist[ny][nx] == -1)
      {
        q.push(P(ny, nx));
        dist[ny][nx] = dist[p.first][p.second] + 1;
      }
    }
  }
  
  int res = 0;
  rep(i, h) rep(j, w) res = max(res, dist[i][j]);
  
  cout << res << endl;
  
  return 0;
}