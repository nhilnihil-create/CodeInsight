#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int H, W;
  cin >> H >> W;
  vector<string> vec(H);
  rep(i, H) {
    cin >> vec.at(i);
  }
  vector<vector<int>> vec2(H + 2, vector<int>(W + 2));
  rep(i, H + 2) {
    rep(j, W + 2) {
      vec2.at(i).at(j) = 0;
    }
  }
  rep(i, H) {
    rep(j, W) {
      if(vec.at(i).at(j) == '#') {
        vec2.at(i).at(j) += 1;
        vec2.at(i).at(j+1) += 1;
        vec2.at(i).at(j+2) += 1;
        vec2.at(i+1).at(j) += 1;
        vec2.at(i+1).at(j+2) += 1;
        vec2.at(i+2).at(j) += 1;
        vec2.at(i+2).at(j+1) += 1;
        vec2.at(i+2).at(j+2) += 1;
      }
    }
  }
  char CH;
  rep(i, H) {
    rep(j, W) {
      if(vec.at(i).at(j) == '#') {
        cout << "#";
      }
      if(vec.at(i).at(j) == '.') {
        cout << vec2.at(i+1).at(j+1);
      }
    }
    cout << " " << endl;
  }
}