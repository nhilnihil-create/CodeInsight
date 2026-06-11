#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> map(55, vector<char>(55));
  for (int i = 1; i <= H; i++)
  {
    for (int j = 1; j <= W; j++)
    cin >> map[i][j];
  }
  int cnt =0;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      // 上下左右 #判定
      if (map[i][j] == '#' && map[i-1][j] != '#' && map[i][j-1] != '#' && map[i][j+1] != '#' && map[i+1][j] != '#') cnt++;
    }
  }
  if (cnt == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
}