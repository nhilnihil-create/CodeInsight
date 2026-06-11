#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define printVec(v) printf("{"); for (const auto& i : v) { std::cout << i << ", "; } printf("}\n");
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using P = pair<int,int>;
using ll = long long;
const ll INF = 1LL<<60;
const double PI = 3.1415926535897932;
const int MOD = 1e9 + 7;

//cin.tie(0);ios::sync_with_stdio(false);
int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<char>> G(h);
  vector<vector<int>> Dis(h, vector<int>(w));
  vector<vector<bool>> Visited(h, vector<bool>(w));
  ll wall_cnt = 0;
  rep (i, h) {
    rep (j, w) {
      char ch;
      cin >> ch;
      G[i].push_back(ch);
      if (ch == '#') wall_cnt++;
    }
  }

  queue<P> qi;
  qi.push(make_pair(0, 0));
  Visited[0][0] = true;
  vector<int> py = {0, 0, 1, -1};
  vector<int> px = {1, -1, 0, 0};
  while (!qi.empty()) {
    P current = qi.front();
    qi.pop();
    for (int i = 0; i < 4; i++) {
      int new_y = current.first + py[i];
      int new_x = current.second + px[i];
      if (0 <= new_y && 0 <= new_x && new_y < h && new_x < w) {
	if (Visited[new_y][new_x] || G[new_y][new_x] == '#') continue;
	qi.push(make_pair(new_y, new_x));
	Dis[new_y][new_x] = Dis[current.first][current.second] + 1;
	Visited[new_y][new_x] = true;
      }
    }
  }

  //for (int i = 0; i < h; i++) {
  //  for (int j = 0; j < w; j++) {
  //    cout << Dis[i][j] << " ";
  //  }
  //  cout << endl;
  //}
  if (Dis[h - 1][w - 1] == 0) {
    cout << -1 << endl;
  } else {
    cout << (h * w) - wall_cnt - Dis[h - 1][w - 1] - 1 << endl;
  }
  return 0;
}
