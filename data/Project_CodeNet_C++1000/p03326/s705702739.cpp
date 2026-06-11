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

int main() {
  int n,m;
  cin>>n>>m;
  vl X(n),Y(n),Z(n);
  rep(i,n){
    cin>>X[i]>>Y[i]>>Z[i];
  }
  ll ans = 0;

  rep(t,1<<3){
    bitset<3> b(t);
    vi f(3,1);
    rep(k,3)if(b[k] == 0)f[k] = -1;
    vl cakes;
    rep(i,n){
      ll score =  f[0]*X[i]+ f[1]*Y[i]+f[2]*Z[i];
      cakes.push_back(score);
    }
    sort(rng(cakes),greater<ll>());
    ll sum = 0;
    rep(i,m){
      sum+=cakes[i];
    }
    maxs(ans,sum);
  }
  cout<<ans<<endl;
  return 0;
}