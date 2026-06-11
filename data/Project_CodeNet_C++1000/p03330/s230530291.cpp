#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,C;
  cin >> N >> C;
  int D[C][C];
  for (int i = 0; i < C; i++) {
    for (int j = 0; j < C; j++) {
      cin >> D[i][j];
    }
  }
  int c[N][N];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> c[i][j];
      c[i][j]--;
    }
  }
  int cost[C][3];
  for (int i = 0; i < C; i++) {
    cost[i][0] = 0;
    cost[i][1] = 0;
    cost[i][2] = 0;
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int md = (i+j) % 3;
      for (int k = 0; k < C; k++) {
        cost[k][md] += D[c[i][j]][k];
      }
    }
  }

  int ans = 999999999;
  for (int i = 0; i < C; i++) {
    for (int j = 0; j < C; j++) {
      for (int k = 0; k < C; k++) {
        if (i == j || j == k || k == i) {
          continue;
        }
        ans = min(ans,cost[i][0] + cost[j][1] + cost[k][2]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}