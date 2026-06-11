#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> A(H, vector<char>(W));
  vector<vector<int>> M(H, vector<int>(W, 0));
  queue<int> X;
  queue<int> Y;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A.at(i).at(j);
      if (A.at(i).at(j) == '#') {
        X.push(i);
        Y.push(j);
      }
    }
  }
  vector<int> vx = {1, -1, 0, 0};
  vector<int> vy = {0, 0, 1, -1};
  //下準備完了
  while (X.size() > 0) {
    for (int i = 0; i < 4; i++) {
      if ((X.front() + vx.at(i)) >= 0 && (Y.front() + vy.at(i)) >= 0 
          && (X.front() + vx.at(i)) < H && (Y.front() + vy.at(i)) < W
          && A.at(X.front() + vx.at(i)).at(Y.front() + vy.at(i)) == '.' 
          && M.at(X.front() + vx.at(i)).at(Y.front() + vy.at(i)) == 0) {
            X.push(X.front() + vx.at(i));
            Y.push(Y.front() + vy.at(i));
            A.at(X.front() + vx.at(i)).at(Y.front() + vy.at(i)) = '#';
            M.at(X.front() + vx.at(i)).at(Y.front() + vy.at(i)) 
              = M.at(X.front()).at(Y.front()) + 1;
      }
    }
    X.pop();
    Y.pop();
  }
  int ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      ans = max(ans, M.at(i).at(j));
    }
  }
  cout << ans << endl;
}