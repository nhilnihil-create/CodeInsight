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

ll dis(ll a,ll b,ll c,ll d) {
  vl arr{a,b,c,d};
  sort(rng(arr));
  if(arr[0]==0) return LINF;
  return arr[3]-arr[0];
}
  
int main() {
  int N;
  cin >> N;
  vl sum(N+1,0);
  rep(i,N) {
    int x;
    cin >> x;
    sum[i+1] = sum[i]+x;
  }
  ll ans = LINF;
  srep(m,1,N-2) {
    ll l = sum[m+1];
    ll r = sum[N]-sum[m+1];
    ll p1 = *lower_bound(rng(sum),(l+1)/2);
    ll p2 = *(lower_bound(rng(sum),(l+1)/2)-1);
    ll q1 = l-p1;
    ll q2 = l-p2;
    ll r1 = *lower_bound(rng(sum),l+(r+1)/2)-l;
    ll r2 = *(lower_bound(rng(sum),l+(r+1)/2)-1)-l;
    ll s1 = r-r1;
    ll s2 = r-r2;
    chmin(ans,dis(p1,q1,r1,s1));
    chmin(ans,dis(p1,q1,r2,s2));
    chmin(ans,dis(p2,q2,r1,s1));
    chmin(ans,dis(p2,q2,r2,s2));
  }
  cout << ans << endl;
  return 0;
}