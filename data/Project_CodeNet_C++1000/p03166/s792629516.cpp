#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;

vi p;
vector<vi> succ;
vb vis;

int dfs(int v){
  if(vis[v]) return p[v];
  vis[v] = 1;
  int res = 0;
  for(const int& u: succ[v])
    res = max(res, 1 + dfs(u));
  return p[v] = res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m; cin >> n >> m;
  vis.assign(n,0); p.assign(n,0); succ.assign(n,vi());
  rep(i,0,m){
    int a, b; cin >> a >> b;
    succ[b-1].push_back(a-1);
  }
  int res = 0;
  rep(i,0,n){
    if(!vis[i]) res = max(res, dfs(i));
  }
  cout << res << "\n";
}
