#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, j, n) for(int i=j;i<n;++i)
#define all(i) i.begin(),i.end()
#define rall(i) i.rbegin(),i.rend()
#define INF 1e9
#define LINF 1e18
const int mod = 1e9 + 7;
 
typedef long long i64;
typedef pair<int, int> pi;
 
template <class T> using vt = vector<T>;
template <class T> using vvt = vector<vector<T>>;
 
i64 gcd(i64 n, i64 m) {return (m == 0? n : gcd(m, n % m));}
i64 lcm(i64 n, i64 m) {return (n / gcd(n, m) * m);}
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
 
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w, n;
  cin >> h >> w >> n;

  vvt<int> grid(w);
  rep(i, 0, n) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    grid[y].push_back(x);
  }
  sort(all(grid[0]));
  rep(i, 1, w) {
    grid[i].push_back(i - 1);
    sort(all(grid[i]));
  }

  int ans = INF, cnt = 0;
  int y = 0;
  rep(i, 0, w) {
    int lim = h;
    for(auto &it : grid[i]) {
      if(it > y) {
        lim = it;
        break;
      }
    }

    ans = min(ans, lim - y + cnt);
    int nxt = y + 1;
    if(i != w - 1) {
      for(auto &it : grid[i + 1]) {
        if(it == nxt) nxt++;
      }
    }
    cnt += nxt - y;
    y = nxt;
    if(y == lim) break;
  }
  cout << ans << endl;
}
