#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  vector<vector<char>> s(H + 2, vector<char>(W + 2, '.'));
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> s.at(i).at(j);
    }
  }
  bool ok = true;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      if (s.at(i).at(j) == '#') {
        if (s.at(i - 1).at(j) == '.' && s.at(i + 1).at(j) == '.' && s.at(i).at(j + 1) == '.' && s.at(i).at(j - 1) == '.') {
          ok = false;
          break;
        }
      }
    }
    if (ok == false) {
      break;
    }
  }
  if (ok) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
  