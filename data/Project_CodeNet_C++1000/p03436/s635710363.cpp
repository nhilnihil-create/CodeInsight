#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;

int main() {
  int h, w;
  cin >> h >> w;
  int count = 0;

  vector<vector<char>> s(h, vector<char>(w));
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> s[i][j];
      if (s[i][j] == '.') count++;
    }
  }

  vector<vector<int>> dist(h, vector<int>(w, -1));

  queue<pair<int, int>> que;

  vector<pii> record;

  que.push({0, 0});
  dist[0][0] = 0;

  while (!que.empty()) {
    pii temp = que.front();
    que.pop();

    for (int i = 0; i < 4; i++) {
      pii t = {temp.first + dx[i], temp.second + dy[i]};

      if (t.first >= 0 && t.first < h && t.second >= 0 && t.second < w &&
          dist[t.first][t.second] == -1 && s[t.first][t.second] != '#') {
        dist[t.first][t.second] = dist[temp.first][temp.second] + 1;
        que.push(t);
        record.push_back(t);
      }
    }
  }

  int ans = count - dist[h - 1][w - 1] - 1;

  cout << (dist[h - 1][w - 1] == -1 ? -1 : ans) << endl;
}
