#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

const int N = 305;
int board[N][N];
int dist[N*N];
pair<int,int> location[N*N];

signed main() {
  int h,w,d;
  cin >> h >> w >> d;

  rep(i,h) rep(j,w) {
    int val; cin >> val;
    board[i][j] = val;
    location[val] = {i, j};
  }

  for (int cur = 1; cur <= h * w; cur++) {
    if(cur - d <= 0) continue;
    if(dist[cur] != 0) continue;
    int from =  cur - d;
    int distance = abs(location[cur].first - location[from].first)
            + abs(location[cur].second - location[from].second);
    dist[cur] = dist[from] + distance;
  }

  int q;
  cin >> q;
  while(q--) {
    int l, r;
    cin >> l >> r;

    int ans = dist[r] - dist[l];
    cout << ans << '\n';
  }


}