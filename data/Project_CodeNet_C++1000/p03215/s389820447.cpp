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
  
int main() {
  int N,K;
  cin >> N >> K;
  vi A(N);
  rep(i,N) {
    cin >> A[i];
  }
  vl sum(N+1,0);
  rep(i,N) {
    sum[i+1] = sum[i] + A[i];
  }
  ll ans = 0;
  drep(k,50) {
    int cnt = 0;
    ll tar = ans + ((1ll)<<k);
    rep(i,N) {
      srep(j,i,N) {
        ll num = sum[j+1]-sum[i];
        if((num&tar)==tar) cnt++;
      }
    }
    if(cnt>=K) {
      ans = tar;
    }
  }
  cout << ans << endl;
  
  return 0;
}