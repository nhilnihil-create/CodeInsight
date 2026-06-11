#include <iostream>
#include <string>
#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int H, W;
  cin >> H >> W;

  vector<int> X = {0, -1, 1, 0};
  vector<int> Y = {-1, 0, 0, 1};

  vector<vector<char>> s(H);
  rep(i, H) {
    s[i].resize(W);
    rep(j, W) {
      cin >> s[i][j];
    }
  }

  bool achieve = true;
  rep(i, H) {
    rep(j, W) {
      if (s[i][j] == '#') {
        bool black = false;
        rep(k, X.size()) {
          if ((0 <= j + X[k] && j + X[k] <= W - 1) 
            &&(0 <= i + Y[k] && i + Y[k] <= H - 1)) {
              if (s[i+Y[k]][j+X[k]] == '#') black = true;
          }
        }
        if (black == false) {
          achieve = false;
          break;
        }
      }
    }
  }

  if (achieve) cout << "Yes" << endl;
  else cout << "No" << endl;

  return 0;
}
