#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using P = pair<int, int>;
const int INF = 1001001001;
ll MOD = 1e9 + 7;

int main() {
  int N, C;
  cin >> N >> C;
  vector<vector<ll>> d(C + 1, vector<ll>(C + 1));
  for (int i = 1; i <= C; i++) {
    for (int j = 1; j <= C; j++) {
      cin >> d[i][j];
    }
  }
  vector<vector<ll>> c(3, vector<ll>(C + 1, 0));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      ll x;
      cin >> x;
      c[(i + j) % 3][x]++;
    }
  }
  ll ans = 1000000010;
  for (int i = 1; i <= C; i++) {    // rest 0
    for (int j = 1; j <= C; j++) {  // rest 1
      if (i == j) continue;
      for (int k = 1; k <= C; k++) {  // rest 2
        if (i == k || j == k) continue;
        ll sum = 0;
        for (int l = 1; l <= C; l++) sum += c[0][l] * d[l][i];
        for (int l = 1; l <= C; l++) sum += c[1][l] * d[l][j];
        for (int l = 1; l <= C; l++) sum += c[2][l] * d[l][k];
        ans = min(ans, sum);
      }
    }
  }
  cout << ans << endl;
}
