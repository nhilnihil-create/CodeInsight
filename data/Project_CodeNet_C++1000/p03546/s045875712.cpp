// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(ll __x = __start; __x < __end; __x++)

typedef pair<int, int> Edge;

int main() {
  int h, w; cin >> h >> w;
  const int INF = 1000000000;
  int G[10][10];
  loop(i,0,10) loop(j,0,10) 
    if (i==j) G[i][j] = G[j][i] = 0;
    else G[i][j] = G[j][i] = INF;
  loop(i,0,10) loop(j,0,10) {
    int w; cin >> w;
    if (w==0) continue;
    G[i][j] = w;
  }
  loop(k,0,10) loop(i,0,10) {
    if (G[i][k] == INF) continue;
    loop(j,0,10) {
      if (G[k][j] == INF) continue;
      G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
    }
  }
  
  ll ans = 0;
  loop(y,0,h) loop(x,0,w) {
    int a; cin >> a;
    if (a == -1) continue;
    ans += G[a][1];
  }
  cout << ans << endl;
  return 0;
}
