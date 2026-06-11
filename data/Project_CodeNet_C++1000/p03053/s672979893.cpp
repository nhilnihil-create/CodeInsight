#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int h, w;
vector<string> a;

int vectormax(vector<vector<int>> dist) {
  int ans = 0;
  for (int i = 0; i < dist.size(); i++) {
    ans = max(ans, *max_element(dist[i].begin(), dist[i].end()));
  }
  return ans;
}

int main() {
  cin >> h >> w;
  a.resize(h);
  for (int i = 0; i < h; i++) {
    cin >> a[i];
  }
  queue<pair<int, int>> que;
  vector<vector<int>> dist(h, vector<int>(w, -1));

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (a[i][j] == '#') {
        dist[i][j] = 0;
        que.push(make_pair(i, j));
      }
    }
  }

  while (!que.empty()) {
    pair<int, int> temp = que.front();
    que.pop();

    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
      int x, y;
      x = temp.first + dx[i];
      y = temp.second + dy[i];
      if (x >= 0 && x < h && y >= 0 && y < w && dist[x][y] == -1) {
        dist[x][y] = dist[temp.first][temp.second] + 1;
        que.emplace(make_pair(x, y));
      }
    }
  }

  cout << vectormax(dist) << endl;
}
