#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
  int N, C;
  cin >> N >> C;
  vector<vector<int> > color_cost_list(C, vector<int>(C));
  for (int i = 0; i < C; i++) {
    for (int j = 0; j < C; j++) {
      cin >> color_cost_list[i][j];
    }
  }

  vector<vector<int> > grid(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> grid[i][j];
      grid[i][j]--;
    }
  }
  
  // グリッドを3つに塗り分ける。その際の各カラー毎のコスト
  vector<vector<int> > grid_color(3, vector<int>(C));
  for (int c = 0; c < C; c++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        grid_color[(i + j) % 3][c] += color_cost_list[grid[i][j]][c];
      }
    }
  }

  int ans = INT_MAX;
  for (int i = 0; i < C; i++) {
    for (int j = 0; j < C; j++) {
      for (int k = 0; k < C; k++) {
        // 色がかぶる場合
        if (i == j || j == k || i == k) {
          continue;
        }
        ans = min(ans, grid_color[0][i] + grid_color[1][j] + grid_color[2][k]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
