#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
int cost[10][10], a[200][200], dist[10][10]; 
int main() {
  int h,w;
  cin >> h >> w;
  rep(i,10) rep(j,10) cin >> dist[i][j];
  rep(i,h) rep(j,w) cin >> a[i][j];

  rep(k,10) rep(i,10) rep(j,10) {
    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
  }
  int ans = 0;
  rep(i,h) rep(j,w) {
    if (a[i][j] == -1) continue;
    int num = a[i][j];
    ans += dist[num][1];
  }
  cout << ans << endl;
  return 0;
}