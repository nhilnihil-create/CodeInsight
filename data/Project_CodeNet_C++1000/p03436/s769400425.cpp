#include <bits/stdc++.h>
using namespace std;
vector<int> dy = {1, 0, -1, 0};
vector<int> dx = {0, 1, 0, -1};
int main(){
  int H, W;
  cin >> H >> W;
  vector<vector<char>> s(H + 2, vector<char>(W + 2, '#'));
  for (int i = 1; i <= H; i++){
    for (int j = 1; j <= W; j++){
      cin >> s[i][j];
    }
  }
  vector<vector<int>> d(H + 2, vector<int>(W + 2, -1));
  d[1][1] = 1;
  queue<pair<int, int>> Q;
  Q.push(make_pair(1, 1));
  while (!Q.empty()){
    int y = Q.front().first;
    int x = Q.front().second;
    Q.pop();
    for (int i = 0; i < 4; i++){
      int y2 = y + dy[i];
      int x2 = x + dx[i];
      if (d[y2][x2] == -1 && s[y2][x2] == '.'){
        d[y2][x2] = d[y][x] + 1;
        Q.push(make_pair(y2, x2));
      }
    }
  }
  if (d[H][W] == -1){
    cout << -1 << endl;
  } else {
    int ans = 0;
    for (int i = 1; i <= H; i++){
      for (int j = 1; j <= W; j++){
        if (s[i][j] == '.'){
          ans++;
        }
      }
    }
    ans -= d[H][W];
    cout << ans << endl;
  }
}