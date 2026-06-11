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
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
const int MOD = 1000000007;

class rMq {
  public:
  int N;
  vl segtree;
  rMq(int n) {
    N = 1;
    int len = 1;
    while(N < n) {
      N *= 2;
      len += N;
    }
    segtree = vl(len,-LINF);
  }
  void build(int idx,ll val) {
    int s = sz(segtree) - (N-idx);
    segtree[s] = val;
    while(1) {
      if(s == 0) break;
      s = (s-1)/2;
      segtree[s] = max(segtree[s*2+1],segtree[s*2+2]);
    }
  }
  ll _query(int a,int b,int idx,int l,int r) {
    if(a <= l && r <= b) return segtree[idx];
    if(r <= a || b <= l) return -LINF;
    ll vl = _query(a,b,idx*2+1,l,(l+r)/2);
    ll rl = _query(a,b,idx*2+2,(l+r)/2,r);
    return max(vl,rl);
  }
  // max(A[i] | l <= i < r)
  ll query(int l,int r) {
    return _query(l,r,0,0,N);
  }
};
  
int main() {
  int N;
  cin >> N;
  vl h(N),a(N);
  rep(i,N) {
    cin >> h[i];
  }
  rep(i,N) {
    cin >> a[i];
  }
  rMq seg(N+3);
  seg.build(0,0);
  rep(i,N) {
    ll r = seg.query(0,h[i]+1)+a[i];
    ll now = seg.query(h[i],h[i]+1);
    if(now<r) {
      seg.build(h[i],r);
    }
  }
  ll ans = seg.query(0,N+3);
  cout << ans << endl;
  return 0;
}