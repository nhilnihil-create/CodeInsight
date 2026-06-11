#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;
int h, w;
string s[1000];
int cost[1000][1000];
pi dyx[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs() {
  queue<pair<int, pi>> q;
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      if (s[i][j] == '#') {
        cost[i][j] = 0;
        q.push(make_pair(0, make_pair(i, j)));
      }
    }
  }
  while (!q.empty()) {
    auto front = q.front();
    q.pop();
    int c;
    pi p;
    tie(c, p) = front;

    for (auto d: dyx) {
      int dy, dx;
      tie(dy, dx) = d;
      int y = p.first + dy;
      int x = p.second + dx;
      if (y < 0 || y >= h || x < 0 || x >= w) {
        continue;
      }
      if (cost[y][x] != -1) {
        continue;
      }
      cost[y][x] = c + 1;
      q.push(make_pair(c + 1, make_pair(y, x)));
    }
  }
}
int main() {
  cin>>h>>w;
  for (int i=0; i<h; i++) cin>>s[i];
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      cost[i][j] = -1;
    }
  }
  bfs();
  int max_cost = 0;
  for (int i=0; i<h; i++) {
    for (int j=0; j<w; j++) {
      max_cost = max(cost[i][j], max_cost);
    }
  }
  cout<<max_cost<<endl;
}