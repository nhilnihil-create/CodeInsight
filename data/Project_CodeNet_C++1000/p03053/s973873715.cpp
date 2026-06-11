#include <bits/stdc++.h>
using namespace std;
int INF = 100000;
vector<int> dx = {0, 1, 0, -1};
vector<int> dy = {1, 0, -1, 0};
int main(){
  int H, W;
  cin >> H >> W;
  vector<string> A(H);
  for (int i = 0; i < H; i++){
    cin >> A[i];
  }
  vector<vector<int>> d(H, vector<int>(W, INF));
  queue<pair<int, int>> Q;
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (A[i][j] == '#'){
        d[i][j] = 0;
        Q.push(make_pair(i, j));
      }
    }
  }
  while (!Q.empty()){
    int y = Q.front().first;
    int x = Q.front().second;
    Q.pop();
    for (int i = 0; i < 4; i++){
      int y2 = y + dy[i];
      int x2 = x + dx[i];
      if (0 <= y2 && y2 < H && 0 <= x2 && x2 < W){
        if (d[y2][x2] == INF){
          d[y2][x2] = d[y][x] + 1;
          Q.push(make_pair(y2, x2));
        }
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      ans = max(ans, d[i][j]);
    }
  }
  cout << ans << endl;
}