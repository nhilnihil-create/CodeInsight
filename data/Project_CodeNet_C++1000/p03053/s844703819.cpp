#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h);
  rep(i, h) cin >> s[i];

  vector<vector<int>> dist(h, vector<int>(w, INF));
  queue<P> q;
  rep(i, h) rep(j, w) if (s[i][j] == '#') {
    q.emplace(i, j);
    dist[i][j] = 0;
  }
  while (!q.empty()) {
    int x = q.front().first;
    int y = q.front().second;
    q.pop();
    auto push = [&]{
      rep(i, 4) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < h && 0 <= ny && ny < w && dist[nx][ny] == INF) {
          dist[nx][ny] = dist[x][y] + 1;
          q.emplace(nx, ny);
        }
      }
    };
    push();
  }

  int ans = 0;
  rep(i, h)rep(j, w) {
    chmax(ans, dist[i][j]);
  }
  cout << ans << endl;

}