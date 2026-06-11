#include <bits/stdc++.h>
using namespace std;


/* エイリアス */
#define ll long long
#define ld long double
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define endl '\n'

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define em emplace
#define mp make_pair


/* 関数マクロ */
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define rep2(i, n, m) for (ll i = n; i <= m; ++i)
#define rep3(i, n, m) for (ll i = n; i >= m; --i)
#define all(v) v.begin(), v.end()
#define si(v) int(v.size())
#define UNIQUE(v) sort(all(v)), v.erase(unique(all(v)),v.end())


/* 定数 */
const ll mod = 1e9 + 7;
const ll infll = (1LL << 62) - 1;
const ll inf = (1LL << 30) - 1;


/* その他 */
template<class S, class T> inline bool chmax(S &a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class S, class T> inline bool chmin(S &a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

signed main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  int h, w; cin >> h >> w;
  char c[h][w];

  rep(i, h) rep(j, w) cin >> c[i][j];

  queue<pii> que;
  que.em(0, 0);
  int vs[h][w];

  rep(i, h) rep(j, w) vs[i][j] = -1;
  vs[0][0] = 0;

  while (!que.empty()) {
    auto p = que.front(); que.pop();
    int x = p.fi, y = p.se;

    rep(i, 4) {
      int nx = x + dx[i], ny = y + dy[i];
      if (nx < 0 || ny < 0 || nx >= w || ny >= h) continue;
      if (vs[ny][nx] != -1 || c[ny][nx] == '#') continue;

      vs[ny][nx] = vs[y][x] + 1;
      que.em(nx, ny);
    }
  }

  if (vs[h-1][w-1] == -1) {
    cout << -1 << endl;
    return (0);
  }

  int sum = vs[h-1][w-1] + 1;
  int ans = 0;

  rep(i, h) rep(j, w) if (c[i][j] == '.') ++ans;
  cout << ans - sum << endl;
}
