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
string s[100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main() {
  cin >> H >> W;
  rep(i, 0, H) { cin >> s[i]; }

  rep(i, 0, H) {
    rep(j, 0, W) {
      if (s[i][j] == '#') {
        bool ok = false;
        rep(k, 0, 4) {
          int ni = i + dx[k];
          int nj = j + dy[k];
          if (ni < 0 || ni >= H) continue;
          if (nj < 0 || nj >= W) continue;
          if (s[ni][nj] == '#') ok = true;
        }
        if (!ok) {
          cout << "No" << endl;
          return 0;
        }
      }
    }
  }

  cout << "Yes" << endl;
}