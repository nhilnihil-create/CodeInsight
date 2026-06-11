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

int H, W;
int c[10][10];

int cost[20][10][10];

void warshalfloyd() {
  repe(i, 0, 9) {
    repe(j, 0, 9) { cost[0][i][j] = c[i][j]; }
  }

  repe(k, 1, 10) {
    repe(i, 0, 9) {
      repe(j, 0, 9) {
        cost[k][i][j] = min(cost[k - 1][i][j],
                            cost[k - 1][i][k - 1] + cost[k - 1][k - 1][j]);
      }
    }
  }
}

int main() {
  cin >> H >> W;
  repe(i, 0, 9) {
    repe(j, 0, 9) { cin >> c[i][j]; }
  }

  warshalfloyd();

  int ans = 0;
  repe(i, 1, H) {
    repe(j, 1, W) {
      int a;
      cin >> a;
      if (a != -1) ans += cost[10][a][1];
    }
  }

  cout << ans << endl;
}
