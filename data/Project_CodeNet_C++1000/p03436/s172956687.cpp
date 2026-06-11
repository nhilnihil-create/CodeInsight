#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  int h, w, cntw = 0;
  cin >> h >> w;
  vector<vector<int>> v(h+2, vector<int>(w+2, -2));
  queue<pair<int,int>> q;
  rep(i, 1, h+1) {
    rep(j, 1, w+1) {
      char c;
      cin >> c;
      if(c == '#') {
        v[i][j] = -2;
      } else {
        v[i][j] = -1;
        cntw++;
      }
    }
  }
  q.push(make_pair(1, 1));
  while(!q.empty()) {
    pair<int, int> f = q.front();
    q.pop();
    int x = f.first, y = f.second;
    if(v[x+1][y] == -1) {
      v[x+1][y] = v[x][y] + 1;
      q.push(make_pair(x+1, y));
    }
      if(v[x-1][y] == -1) {
      v[x-1][y] = v[x][y] + 1;
      q.push(make_pair(x-1, y));
    }
      if(v[x][y+1] == -1) {
      v[x][y+1] = v[x][y] + 1;
      q.push(make_pair(x, y+1));
    }
      if(v[x][y-1] == -1) {
      v[x][y-1] = v[x][y] + 1;
      q.push(make_pair(x, y-1));
    }
  }
  if(v[h][w] == -1) cout << -1 << "\n";
  else cout << cntw - v[h][w] - 2 << "\n";
}