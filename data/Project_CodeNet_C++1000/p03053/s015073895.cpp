#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using P = pair<int, int>;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> maze(H);
  queue<P> que;
  for (int y = 0; y < H; y++) {
    cin >> maze[y];
    for (int x = 0; x < W; x++) {
      if (maze[y][x] == '#') {
        que.push(P(y, x));
      }
    }
  }
  int count = 0;
  while (!que.empty()) {
    int a = que.size();
    int y[4] = {1, 0, -1, 0};
    int x[4] = {0, 1, 0, -1};
    for (int i = 0; i < a; i++) {
      P p = que.front(); que.pop();
      
      for (int j = 0; j < 4; j++) {
        int ny = p.first + y[j];
        int nx = p.second + x[j];
        
        if (ny >= 0 && ny < H && nx >= 0 && nx < W && 
             maze[ny][nx] == '.') {
          maze[ny][nx] = '#';
          que.push(P(ny, nx));
        }
      }
    }
    
    if (!que.empty()) count++;
  }
  
  cout << count << endl;
}