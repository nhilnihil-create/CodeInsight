#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define print(x)cout<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;

vi TopologicalSort(const vector<vi>& g) {
  const int v = g.size();
  vi indeg(v, 0);
  stack<int> st;

  for (auto& out_edges : g)
    for (auto& v : out_edges) indeg[v]++;

  rep(i, v) {
    if (indeg[i] == 0) st.push(i);
  }

  vi ans;
  while (st.size() > 0) {
    int u = st.top();
    st.pop();
    ans.emplace_back(u);
    for (auto& v : g[u]) {
      indeg[v]--;
      if (indeg[v] == 0) st.push(v);
    }
  }
  return ans;
}



int main() {
  int n,m;
  cin >> n >> m;
  vector<vi> G(n,vi());
  vi depth(n,0),ans(n,0);
  rep(i,n-1+m){
    int u,v;
    cin >> u >> v;
    u--;v--;
    G[u].push_back(v);
  }
  auto res = TopologicalSort(G);
  for(auto u:res){
    for(auto v: G[u]){
      maxs(depth[v],depth[u]+1);
    }
  }

  rep(u,n){
    for(auto v: G[u]){
      if(depth[u]+1 == depth[v]) ans[v] = u+1;
    }
  }
  rep(i,n){
    cout<<ans[i]<<endl;
  }
  return 0;
}