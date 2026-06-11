#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

typedef pair<int, int> P;

queue<P> que;
int H, W;
char maze[1000][1000];
int r[1000][1000];

int bfs() {

  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      if(maze[i][j] == '#') {
        que.push(P(i, j));
        r[i][j] = 0;
      }
    }
  }


    while(que.size()) {
      P p = que.front();
      que.pop();
      int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
      for(int i = 0; i < 4; i++) {
        int nx = p.first + dx[i];
        int ny = p.second + dy[i];
        if(0 <= nx && nx < H && 0 <= ny && ny < W && maze[nx][ny] == '.') {
          que.push(P(nx, ny));
          maze[nx][ny] = '#';
          r[nx][ny] = r[p.first][p.second] + 1;
        }
      }

    }

  int ans = 0;
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      ans = max(ans, r[i][j]);
      }
    }
  return ans;

}



int main() {
  cin >> H >> W;
  for(int i = 0; i < H; i++) {
    for(int j = 0; j < W; j++) {
      cin >> maze[i][j];
    }
  }

  int res = bfs();
  cout << res << endl;

  return 0;
}