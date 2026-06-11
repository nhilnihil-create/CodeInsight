#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans(1000000, vector<int>(4));
vector<vector<int>> a(501, vector<int>(501));
int n = 0;

void pushToAns(int x, int b, int c, int d) {
  a[x][b]--;
  a[c][d]++;
  ans[n][0] = x + 1;
  ans[n][1] = b + 1;
  ans[n][2] = c + 1;
  ans[n][3] = d + 1;
  n++;
  return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int H, W;
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (a[i][j] % 2 == 1 && a[i][j] > 0) {
        if (i < H - 1 && (a[i + 1][j] % 2 == 1 || j == W-1)) {
          pushToAns(i, j, i + 1, j);
        } else if(j < W - 1){
          pushToAns(i, j, i, j + 1);
        } 
      }
    }
  }
  cout << n << endl;
  for (int i = 0; i < n; i++) {
    cout << ans[i][0] << " " << ans[i][1] << " " << ans[i][2] << " "
         << ans[i][3] << endl;
  }
}
