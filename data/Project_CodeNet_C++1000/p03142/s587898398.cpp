#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define uni(x) x.erase(unique(rng(x)),x.end())
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
#define EPS (1e-10)
#define equals(a, b) (fabs((a)-(b)) < EPS)
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef set<int> S;
typedef queue<int> Q;
typedef queue<P> QP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<double> vd;
typedef pair<double,double> PD;
typedef pair<int,P> ed;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;

vvi to;
v(bool) used;
vi vs;

void dfs(int k) {
  used[k]=true;
  for(int t:to[k]) {
    if(!used[t]) {
      dfs(t);
    }
  }
  vs.push_back(k);
}
  
int main() {
  int N,M;
  cin >> N >> M;
  to = vvi(N+1);
  used = v(bool)(N+1,false);
  rep(i,N+M-1) {
    int a,b;
    cin >> a >> b;
    to[a].push_back(b);
  }
  srep(i,1,N+1) {
    if(!used[i]) {
      dfs(i);
    }
  }
  reverse(rng(vs));
  vi ans(N+1,0);
  for(int n:vs) {
    for(int t:to[n]) {
      ans[t] = n;
    }
  }
  srep(i,1,N+1) {
    cout << ans[i] << endl;
  }
  return 0;
}