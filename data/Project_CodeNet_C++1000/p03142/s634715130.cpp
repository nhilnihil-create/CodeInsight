#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(ll i = 0; i < n; i++)
#define Rep(i,n) for(ll i = 0; i <= n; i++)
#define REp(i,n) for(ll i = 1; i < n; i++)
#define REP(i,n) for(ll i = 1; i <= n; i++)
#define sz(x) int(x.size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define YesorNo(a) printf(a ? "Yes\n" : "No\n")
#define endl '\n'
#define fi first
#define se second
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
template<class T> using V = vector<T>;
const int dx[] = {0,1,0,-1,1,1,-1,-1};
const int dy[] = {1,0,-1,0,1,-1,-1,1};
const int inf = (1<<30)-1;
const ll infll = (1LL<<62)-1;
ll ceil(const ll &a, const ll &b){return ((a)+(b)-1)/b;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void bfs(int root, V<int> &dist, const V<V<int>> &to, const V<V<int>> &from, V<int> &cnt) {
  queue<int> q;
  q.push(root);
  while(sz(q)) {
    int v = q.front(); q.pop();
    for(int nv : to[v]) {
      cnt[nv]++;
      chmax(dist[nv], dist[v] + 1);
      if(cnt[nv] == sz(from[nv])) q.push(nv);
    }
  }
}

int main(){
  int n, m;
  cin >> n >> m;
  V<V<int>> to(n);
  V<V<int>> from(n);
  rep(i,n+m-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    to[a].push_back(b);
    from[b].push_back(a);
  }
  int root = 0;
  rep(i,n) if(from[i].empty()) root = i;
  V<int> dist(n,-1);
  dist[root] = 0;
  V<int> cnt(n);
  bfs(root, dist, to, from, cnt);
  // rep(i,n) printf("%d:%d\n", (int)i, dist[i]);
  rep(i,n) {
    int p = sz(from[i]);
    if(p == 0) cout << 0 << endl;
    else if(p == 1) cout << from[i][0]+1 << endl;
    else {
      int ans = 0;
      for(int parent : from[i]) {
        if(dist[parent]+1 == dist[i]) ans = parent+1;
      }
      cout << ans << endl;
    }
  }
}