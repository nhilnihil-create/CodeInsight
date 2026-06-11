#include <bits/stdc++.h>
using namespace std;

using Field = vector<string>;

int main() {
  int H, W; cin >> H >> W;
  Field field(H);
  for (int i = 0; i < H; i++) cin >> field[i];
  
  vector<int> dx = {1, 0, -1, 0};
  vector<int> dy = {0, 1, 0, -1};
  
  queue<pair<int, int>> que;
  vector<vector<int>> dist(H, vector<int>(W, -1));
  
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (field[i][j] == '#') {
        dist[i][j] = 0;
        que.push(make_pair(i, j));
      }
    }
  }
  
  while (!que.empty()) {
    int i = que.front().first;
    int j = que.front().second;
    
    // cout << i << ' ' << j << endl;
    
    que.pop();
    
    for (int dir = 0; dir < 4; dir++) {
      int nx = j + dx[dir];
      int ny = i + dy[dir];
        
      if (nx < 0 || W <= nx || ny < 0 || H <= ny) continue;
      if (dist[ny][nx] != -1) continue;
      
      dist[ny][nx] = dist[i][j] + 1;
      que.push(make_pair(ny, nx));
    }
  }
  
  int ans = -1;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      ans = max(ans, dist[i][j]);
    }
  }
  
  cout << ans << endl;  
}