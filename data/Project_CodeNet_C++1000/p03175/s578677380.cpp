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
const ll mod = 1000000007LL;
ll dp[100100][2];
vector<int> G[100100];
vector<int> visit(100100,0);
void dfs(int u, int p){
  // if(visit[u]) return;
  // visit[u] = 1;
  dp[u][0] = 1;
  dp[u][1] = 1;
  for(auto v: G[u]){
    if(v == p) continue;
    dfs(v,u);
    dp[u][0] = dp[u][0]*(dp[v][0]+dp[v][1])%mod;
    dp[u][1] = dp[u][1]*dp[v][0]%mod;
  }
}

int main() {
  int n;
  cin >> n;
  rep(i,n-1){
    int x,y;
    cin >> x >> y;
    x--;y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  dfs(0,-1);
  cout<<(dp[0][0]+dp[0][1])%mod<<endl;
  return 0;
}