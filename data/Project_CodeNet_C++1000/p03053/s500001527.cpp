/*
g++ --std=c++17 A.cpp
*/

#include <iostream>
#include <iomanip> //! for setprecision(20)
#include <math.h>
#include <algorithm>
#include <functional> 
#include <string>
#include <vector>

#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <utility>
#include <limits.h>

using namespace std;

typedef long long LL;

#define rep(i,n) for (int i = 0; i < int(n); ++i)
template<class T> inline bool chmax(T& a, T b) { bool ret = (a < b); if (ret) { a = b; } return ret; }
template<class T> inline bool chmin(T& a, T b) { bool ret = (b < a); if (ret) { a = b; } return ret; }
#define dump(c) { for (auto it = c.begin(); it != c.end(); ++it) if (it == c.begin()) cout << *it; else cout << ' ' << *it; cout << endl; } 
#define dumpMap(m) { for (auto it: m) cout << it.first << "=>" << it.second << ' '; }

const int INF = 1e9;
const LL INFL = 1e18;
const int MOD = 1000000007;


int dx[] = { 0, -1, 1, 0 };
int dy[] = { -1, 0, 0, 1 };

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(0);

  int h, w;
  cin >> h >> w;
  vector<string> a(h);
  rep(i, h) cin >> a[i];

  queue<pair<int, int>> q;
  int white = h * w;
  rep(y, h) rep(x, w) {
    if (a[y][x] == '#') {
      q.emplace(y, x);
      --white;
    }
  }

  int ans = 0;
  while (0 < white && !q.empty()) {
    queue<pair<int, int>> nq;
    ++ans;
    while (!q.empty()) {
      int cy = q.front().first; 
      int cx = q.front().second;
      rep(i, 4) {
        int y = cy + dy[i];
        int x = cx + dx[i];
        if (0 <= x && x < w && 0 <= y && y < h && a[y][x] == '.') {
          a[y][x] = '#';
          nq.emplace(y, x);
          --white;
        }
      }
      q.pop();
    }
    q.swap(nq);
  }

  cout << ans << endl;

  return 0;
}