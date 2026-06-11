#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("O0")
typedef long long int ll;
typedef long double ld;
const ll mod = 1e9+7;
const ll INF = 1e18;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define Rep(i,a,n) for (ll i = (a); i < (n); ++i)
#define All(a) (a).begin(),(a).end()
#define Pi acos(-1)
using Graph = vector<vector<ll>>;
using V = vector<ll>;
using P = pair<ll,ll>;

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << setprecision(15) << fixed;
  chrono::system_clock::time_point start,end;
  start = chrono::system_clock::now();

  ll h, w;
  cin >> h >> w;
  vector<string> grid(h);
  rep(i,h) cin >> grid[i];
  queue<P> q;
  Graph d(h, V(w,-1));
  rep(i,h) rep(j,w) {
    if (grid[i][j] == '#') {
      d[i][j] = 0;
      q.push(make_pair(i,j));
    }
  }
  ll ans = 0;
  vector dy = {0,1,0,-1};
  vector dx = {1,0,-1,0};
  while (!q.empty()) {
    ll y = q.front().first, x = q.front().second;
    rep(i,4) {
      ll ny = y+dy[i], nx = x+dx[i];
      if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
      if (d[ny][nx] == -1 && grid[ny][nx] == '.') {
        d[ny][nx] = d[y][x]+1;
        q.push(make_pair(ny,nx));
        ans = max(d[ny][nx],ans);
      }
    }
    q.pop();
  }
  cout << ans << '\n';

  end = chrono::system_clock::now();
  auto elapsed = chrono::duration_cast< chrono::milliseconds >(end - start).count();
  cerr << elapsed << "ms" << '\n';
}