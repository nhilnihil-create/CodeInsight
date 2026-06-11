#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
bool ok (char c, int i) {
  switch (i) {
    case 0: if (c == 'U') return true; break;
    case 1: if (c == 'R') return true; break;
    case 2: if (c == 'D') return true; break;
    case 3: if (c == 'L') return true; break;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h, w, n, sx, sy;
  string s, t;
  cin >> h >> w >> n >> sx >> sy >> s >> t;
  sx--, sy--;
  rep(i, 4) {
    int x = sx, y = sy;
    rep(j, n) {
      if (ok(s[j], i))
        x += dx[i], y += dy[i];
      if (x < 0 || x >= h || y < 0 || y >= w) {
        cout << "NO" << endl;
        return 0;
      }
      int k = (i+2)%4;
      if (ok(t[j], k) && x+dx[k] >= 0 && x+dx[k] < h && y+dy[k] >= 0 && y+dy[k] < w) {
        x += dx[k], y += dy[k];
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}