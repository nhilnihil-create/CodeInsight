#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

string s[50];
bool isVisited[50][50];
int move_h[4] = {1,-1,0,0};
int move_w[4] = {0,0,1,-1};

int main() {
  int H, W; cin >> H >> W;
  rep(h,H) cin >> s[h];
  // cout << "input ok" << endl;
  
  queue<pair<P,int>> grid;
  grid.push(make_pair(make_pair(0,0), 1));

  int cost = -1;
  bool reach_end = false;
  
  while (!grid.empty() && !reach_end) {
    int temp_h = grid.front().first.first;
    int temp_w = grid.front().first.second;
    int temp_t = grid.front().second;
    // cout << temp_h << "," << temp_w << ": " << temp_t << endl;
    grid.pop();
    rep(i,4) {
      if (temp_h + move_h[i] >= 0 && temp_h + move_h[i] <= H-1 && \
          temp_w + move_w[i] >= 0 && temp_w + move_w[i] <= W-1 && \
          s[temp_h + move_h[i]][temp_w + move_w[i]] == '.' && \
          (!isVisited[temp_h + move_h[i]][temp_w + move_w[i]])) {
            if (temp_h + move_h[i] == H-1 && temp_w + move_w[i] == W-1) {
              cost = temp_t + 1;
              isVisited[H-1][W-1] = true;
              reach_end = true;
            }
            else {
              grid.push(make_pair(make_pair(temp_h + move_h[i], temp_w + move_w[i]), temp_t+1));
              isVisited[temp_h + move_h[i]][temp_w + move_w[i]] = true;
            }
      }
    }
  }
  if (cost == -1) cout << -1 << endl;
  else {
    int total_white = 0;
    rep(i,H) rep(j,W) {
      if (s[i][j]=='.') total_white++;
    }
    cout << total_white - cost << endl;
  }

  return 0;
}