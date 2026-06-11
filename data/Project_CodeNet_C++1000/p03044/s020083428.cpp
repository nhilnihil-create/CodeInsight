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

struct edge{
  int to;
  ll cost;
};

vector<edge> G[100005];

int main() {
  int n;
  cin >> n;
  rep(i,n-1){
    int a,b;
    ll w;
    cin >> a >> b >> w;
    a--;b--;
    edge e1,e2;
    e1.to = b;
    e1.cost=w;
    e2.to = a;
    e2.cost=w;
    G[a].push_back(e1);
    G[b].push_back(e2);
  }
  queue<int> q;
  vi color(n,-1);
  q.push(0);
  color[0] = 0;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(auto ne:G[u]){
      int v = ne.to;
      ll nw = ne.cost;
      if(color[v] != -1)continue;
      if(nw%2)color[v] = !color[u];
      else color[v] = color[u];
      q.push(v);
  }
  }
  rep(i,n)cout<<color[i]<<endl;
  return 0;
}