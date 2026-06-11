#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int ys[4] = {-1, 0, 1, 0};
const int xs[4] = {0, 1, 0, -1};

int main() {
  int H, W;
  cin >> H >> W;
  
  int num_whites = 0;
  vector<string> maze(H);
  for (int h = 0; h < H; ++h) {
    string line;
    cin >> line;
    for (const char c : line) {
      if (c == '.') ++num_whites;
    }
    maze[h] = line;
  }
  queue<pair<int, int>> q;
  vector<vector<int>> dist(H, vector<int>(W));
  q.push({0, 0});
  dist[0][0] = 1;
  bool find = false;
  while (!q.empty()) {
    const auto& cur = q.front(); q.pop();
    if (cur.first+1 == H && cur.second+1 == W) { find = true; break; }
    for (int i = 0; i < 4; ++i) {
      int h = cur.first + ys[i];
      int w = cur.second + xs[i];
      if (h < 0 || H <= h || w < 0 || W <= w) {
        continue;
      }
      if (dist[h][w] == 0) {
        if (maze[h][w] == '#') {
          dist[h][w] = -1;
        } else {
          dist[h][w] = dist[cur.first][cur.second] + 1;
          q.push({h, w});
        }
      }
    }
  }
  if (find) {
    cout << (num_whites - dist[H-1][W-1]) << endl;
  } else {
    cout << -1 << endl;
  }

  return 0;
}
  