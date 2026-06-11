#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------
int H, W;
int d[100][100];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

using Pii = pair<int, int>;

void bfs(int x, int y) {
  queue<pair<Pii, int>> que;
  que.push(make_pair(Pii(x, y), 0));

  while (!que.empty()) {
    auto elem = que.front();
    que.pop();

    int cx = elem.first.first;
    int cy = elem.first.second;
    int cdist = elem.second;

    if (d[cx][cy] != 0) {
      continue;
    }

    d[cx][cy] = cdist;

    rep(i, 0, 4) {
      int nx = cx + dx[i];
      int ny = cy + dy[i];

      if (d[nx][ny] == 0 && !(nx == 1 && ny == 1)) {
        que.push(make_pair(Pii(nx, ny), cdist + 1));
      }
    }
  }
}

void trace_route(int x, int y) {
  int cx = x;
  int cy = y;

  while (!(cx == 1 && cy == 1)) {
    int cdist = d[cx][cy];
    d[cx][cy] = -1;

    rep(i, 0, 4) {
      int nx = cx + dx[i];
      int ny = cy + dy[i];
      if (d[nx][ny] == cdist - 1) {
        cx = nx;
        cy = ny;
        break;
      }
    }
  }

  d[1][1] = -1;
}

int main() {
  cin >> H >> W;
  rep(i, 0, H) {
    string s;
    cin >> s;
    d[i + 1][0] = -1;
    d[i + 1][W + 1] = -1;
    rep(j, 0, W) {
      if (s[j] == '.') {
        d[i + 1][j + 1] = 0;
      } else {
        d[i + 1][j + 1] = -1;
      }
    }
  }
  rep(i, 0, W + 2) {
    d[0][i] = -1;
    d[H + 1][i] = -1;
  }

  bfs(1, 1);

  if (d[H][W] == 0) {
    cout << -1 << endl;
    return 0;
  }

  trace_route(H, W);

  int ans = 0;
  repe(i, 1, H) {
    repe(j, 1, W) {
      if (d[i][j] != -1) ++ans;
    }
  }

  cout << ans << endl;
}
