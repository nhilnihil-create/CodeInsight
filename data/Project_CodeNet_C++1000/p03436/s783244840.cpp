#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int INF = 10000;
vector<vector<char> > M(52, vector<char>(52, '#'));

// 解説見た。再帰を使ったdfs
int main() {
  int h, w;
  cin >> h >> w;
 
  int ans = 0;
  rep(i, h) {
    string s;
    cin >> s;
    rep(j, w) {
      char c = s[j];
      if (c == '.') ans++;
      M[i + 1][j + 1] = c;
    }
  }

  vector<vector<int> > dist(52, vector<int>(52, INF));
  dist[1][1] = 1;

  queue<P> Q;
  Q.push(make_pair(1, 1));
  while(!Q.empty()) {
    P p = Q.front(),first;
    int y = p.first, x = p.second;  // それぞれ行、列
    int d = dist[y][x];
    Q.pop();

    if (M[y - 1][x] == '.' && dist[y - 1][x] == INF) {
      dist[y - 1][x] = d + 1;
      Q.push(make_pair(y - 1, x));
    }

    if (M[y + 1][x] == '.' && dist[y + 1][x] == INF) {
      dist[y + 1][x] = d + 1;
      Q.push(make_pair(y + 1, x));
    }

    if (M[y][x - 1] == '.' && dist[y][x - 1] == INF) {
      dist[y][x - 1] = d + 1;
      Q.push(make_pair(y, x - 1));
    }

    if (M[y][x + 1] == '.' && dist[y][x + 1] == INF) {
      dist[y][x + 1] = d + 1;
      Q.push(make_pair(y, x + 1));
    }
  }

  if (dist[h][w] != INF) {
    ans -= dist[h][w];
  } else {
    ans = -1;
  }
  cout << ans << endl;
  return 0;
}
