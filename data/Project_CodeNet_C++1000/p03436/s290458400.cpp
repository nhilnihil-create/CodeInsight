#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int map_search_for_goal(int now_h, int now_w, int max_h, int max_w, int goal_h,
                        int goal_w, vector<string> data) {
  // initial value
  int fx[] = {0, 1, 0, -1};
  int fy[] = {1, 0, -1, 0};
  int forward_count = 4;
  char forwardable = '.';
  vector<vector<bool>> visited(max_h, vector<bool>(max_w, false));
  vector<vector<int>> dist(max_h, vector<int>(max_w, 0));
  queue<pair<int, int>> q;

  // start
  q.push(make_pair(now_h, now_w));
  visited[now_h][now_w] = true;

  int move_dist = 0;
  while (!q.empty()) {
    pair<int, int> p = q.front();
    q.pop();
    REP(i, forward_count) {
      int next_h = p.first + fx[i];
      int next_w = p.second + fy[i];
      if (next_h >= 0 && next_h < max_h && next_w >= 0 && next_w < max_w &&
          !visited[next_h][next_w] && data[next_h][next_w] == forwardable) {
        visited[next_h][next_w] = true;
        int next_dist = dist[p.first][p.second] + 1;
        dist[next_h][next_w] = next_dist;
        q.push(make_pair(next_h, next_w));
      }
    }
  }
  return dist[goal_h][goal_w];
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> data;
  int wall_count = 0;
  REP(i, h) {
    string s;
    cin >> s;
    REP(j, w) {
      if (s[j] == '#') wall_count++;
    }
    data.push_back(s);
  }

  int len = map_search_for_goal(0, 0, h, w, h - 1, w - 1, data);
  int ans = (h * w) - (len + 1) - wall_count;
  if (len == 0) ans = -1;
  cout << ans << endl;
}