#include <bits/stdc++.h>
using namespace std;
int main() {
  int H, W, black = 0;
  cin >> H >> W;
  string s[H];
  vector<int> d(H*W);
  queue<int> q;
  vector<int> G[H*W];
  vector<bool> visited(H*W);
  for (int i = 0; i < H; i++) {
    cin >> s[i];
    for (char c : s[i]) {
      black += c == '#';
    }
  }
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (i && s[i-1][j] != '#' && s[i][j] != '#') {
        G[i*W+j].push_back((i-1)*W+j);
      }
      if (i+1 < H && s[i+1][j] != '#' && s[i][j] != '#') {
        G[i*W+j].push_back((i+1)*W+j);
      }
      if (j && s[i][j-1] != '#' && s[i][j] != '#') {
        G[i*W+j].push_back(i*W+j-1);
      }
      if (j+1 < W && s[i][j+1] != '#' && s[i][j] != '#') {
        G[i*W+j].push_back(i*W+j+1);
      }
    }
  }
  for (q.push(0), visited[0] = true, d[0] = 1; !q.empty(); q.pop()) {
    for (int v : G[q.front()]) {
      if (!visited[v]) {
        d[v] = d[q.front()]+1;
        q.push(v);
        visited[v] = true;
      }
    }
  }
  if (d.back()) {
    cout << H*W-black-d.back();
  } else {
    cout << -1;
  }
}