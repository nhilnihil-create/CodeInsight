#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i <= (n); ++i)
#define drep(i, n) for (int i = (n)-1; i >= 0; --i)
#define srep(i, s, t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(), a.end()
#define rrng(a) a.rbegin(), a.rend()
#define maxs(x, y) (x = max(x, y))
#define mins(x, y) (x = min(x, y))
#define limit(x, l, r) max(l, min(x, r))
#define lims(x, l, r) (x = max(l, min(x, r)))
#define isin(x, l, r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)), x.end())
#define show(x) cout << #x << " = " << x << endl;
#define PQ(T) priority_queue<T, v(T), greater<T>>
#define bn(x) ((1 << x) - 1)
#define dup(x, y) (((x) + (y)-1) / (y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;

int score, id=0;
int nums[10001],isCheck[10001];
vector<vi> G(10001);
vi c(10001);
void dfs(int v, int parent){
  if(isCheck[v])return;
  isCheck[v] = 1;
  nums[v] = c[id];
  id++;
  for(auto u : G[v]){
    dfs(u,v);
  }
  if(parent>=0){
    score += min(nums[v],nums[parent]);
  }
  return;
}
int main() {
  int n;
  cin >> n;
  vector<P> p(n);
  rep(i,n-1){
    int a,b;
    cin >> a >> b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }  
  rep(i,n) p[i] = P(sz(G[i]),i);
  sort(rng(p),greater<P>());
  rep(i,n) cin >> c[i];
  sort(rng(c),greater<int>());
  nums[p[0].se] = c[0];
  dfs(p[0].se,-1);
  cout<<score<<endl;
  rep(i,n)cout <<nums[i]<< " ";
  cout<<endl;
  return 0;
}