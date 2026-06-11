#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int c[10][10];

void warshall_floyd(int n) {
  for (int k = 0; k < n; k++) {      // 経由する頂点
    for (int i = 0; i < n; i++) {    // 始点
      for (int j = 0; j < n; j++) {  // 終点
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
      }
    }
  }
}

int main() {
  int h, w;
  cin >> h >> w;
  REP(i, 10) {
    REP(j, 10) {
      int x;
      cin >> x;
      c[i][j] = x;
    }
  }
  warshall_floyd(10);
  int ans = 0;
  REP(i, h) {
    REP(j, w) {
      int x;
      cin >> x;
      if (x == -1) continue;
      ans += c[x][1];
    }
  }
  cout << ans << endl;
}