#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<int>> A(H, vector<int>(W));
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> A.at(i).at(j);
    }
  }
  vector<tuple<int, int, int, int>> ans;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j + 1 < W; j++) {
      if (A.at(i).at(j) % 2 == 1) {
        A.at(i).at(j)--;
        A.at(i).at(j + 1)++;
        ans.push_back(make_tuple(i + 1, j + 1, i + 1, j + 2));
      }
    }
  }
  for (int i = 0; i + 1 < H; i++) {
    if (A.at(i).at(W - 1) % 2 == 1) {
      A.at(i).at(W - 1)--;
      A.at(i + 1).at(W - 1)++;
      ans.push_back(make_tuple(i + 1, W, i + 2, W));
    }
  }
  cout << ans.size() << "\n";
  for (auto a : ans) {
    int b, c, d, e;
    tie(b, c, d, e) = a;
    cout << b << " " << c << " " << d << " " << e << "\n"; 
  }
}