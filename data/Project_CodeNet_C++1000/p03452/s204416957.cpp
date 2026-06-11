#include <bits/stdc++.h>
#define int long long
#define uint unsigned int
#define rep(i, a, b) for (int i = a; i < b; i++)
#define repr(i, a, b) for (int i = a; i >= b; i--)
#define all(a) (a).begin(), (a).end()
#define sz(a) (a).size()
#define pb(a) push_back(a)
#define eb(...) emplace_back(__VA_ARGS__)
#define mp(a, b) make_pair(a, b)
#define mt(...) make_tuple(__VA_ARGS__)
using namespace std;
using pii = pair<int, int>;
constexpr int MOD = 1000000007;
constexpr int INF = 1LL << 30;
constexpr double EPS = 1e-10;

struct edge {
  int t, c;
  edge() {}
  edge(int t, int c) : t(t), c(c) {}
};

int N, M;
vector<edge> g[100010];
int dis[100010];

bool dfs(int v, int x) {
  dis[v] = x;
  for (edge e : g[v]) {
    int nv = e.t;
    if (dis[nv] == INF) {
      if (dfs(nv, x+e.c)) continue;
      else return false;
    } else {
      if (dis[nv] == x+e.c) continue;
      return false;
    }
  }
  return true;
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  
  cin >> N >> M;
  rep(i, 0, M) {
    int L, R, D;
    cin >> L >> R >> D;
    L--; R--;
    g[L].eb(R, D);
    g[R].eb(L, -D);
  }

  fill(dis, dis+N, INF);
  rep(i, 0, N) {
    if (dis[i] == INF) {
      if (!dfs(i, 0)) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;

  return 0;
}