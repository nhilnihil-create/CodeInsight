#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using Pii = pair<int, int>;
using Pll = pair<ll, ll>;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T &a, T b) {
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
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
string S[100];
int H, W;
int ans[200][200];

int main() {
  cin >> H >> W;
  rep(i, 0, H) { cin >> S[i]; }
  rep(y, 0, H) {
    rep(x, 0, W) {
      if (S[y][x] == '#') {
        ans[y][x] = -1;
        continue;
      }
      int cnt = 0;
      rep(i, 0, 8) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (0 <= nx && nx < W && 0 <= ny && ny < H) {
          if (S[ny][nx] == '#') {
            ++cnt;
          }
        }
      }
      ans[y][x] = cnt;
    }
  }

  rep(y, 0, H) {
    rep(x, 0, W) {
      if (ans[y][x] == -1) {
        cout << "#";
      } else {
        cout << ans[y][x];
      }
    }
    cout << endl;
  }
}
