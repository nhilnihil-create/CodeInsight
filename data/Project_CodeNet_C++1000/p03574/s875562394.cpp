#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<string> a(H);
  for (int i = 0; i < H; i++){
    cin >> a[i];
  }
  vector<int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
  vector<int> dy = {1, 0, -1, 1, -1, 1, 0, -1};
  
  for (int i = 0; i < H; i++){
    for (int j = 0; j < W; j++){
      if (a[i][j] == '#') cout << '#';
      if (a[i][j] == '.'){
        int cnt = 0;
        for (int k = 0; k < 8; k++){
          if(0 <= i + dy[k] && i + dy[k] < H && 0 <= j + dx[k] && j + dx[k] < W && a[i + dy[k]][j + dx[k]] == '#')
            cnt++;
        }
        cout << cnt;
      }
    }
    cout << endl;
  }
}