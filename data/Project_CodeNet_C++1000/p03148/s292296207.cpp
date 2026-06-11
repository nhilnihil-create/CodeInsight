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
  map<int,vi> mp;
  rep(i,N) {
    int t,d;
    cin >> t >> d;
    mp[t].push_back(d);
  }
  vi ones;
  vi others;
  for(auto x: mp) {
    sort(rng(x.second));
    reverse(rng(x.second));
    rep(i,sz(x.second)) {
      if(i == 0) {
        ones.push_back(x.second[i]);
      } else {
        others.push_back(x.second[i]);
      }
    }
  }
  sort(rng(ones));
  sort(rng(others));
  reverse(rng(ones));
  reverse(rng(others));
  ll ans = 0;
  srep(i,1,sz(ones)+1) {
    if(i>K) break;
    if(K-i > sz(others)) continue;
    ll b = 1l * i*i;
    ll a = 0;
    rep(j,i) {
      a += ones[j];
    }
    rep(j,K-i) {
      a += others[j];
    }
    ans = max(ans,a+b);
  }
  cout << ans << endl;

  return 0;
}