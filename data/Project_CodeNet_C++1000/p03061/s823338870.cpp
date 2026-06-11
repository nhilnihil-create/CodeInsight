#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef queue<ll> ql;
typedef deque<ll> dql;
typedef priority_queue<ll/*, vl, greater<ll>*/> pql; //降順(/*昇順*/)
typedef set<ll> sl;
typedef pair<ll, ll> pl;
typedef pair<pl, ll> ppl;
typedef vector<vl> vvl;
typedef vector<pl> vpl;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define rep2(i, k, n) for(ll i = ll(k); i <= ll(n); i++)
#define rep3(i, n, k) for(ll i = ll(n); i >= ll(k); i--)
#define all(v) (v).begin(), (v).end()
ll mod(ll a, ll b) {if(b == 0) return 0; return (a % b + b) % b;}
bool chmin(ll &a, ll b) {if(b < a) {a = b; return 1;} return 0;}
bool chmax(ll &a, ll b) {if(b > a) {a = b; return 1;} return 0;}
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;
const ll MAX = 1e9;
const char newl = '\n';

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;
  vl a(n);
  rep(i, n) cin >> a[i];

  ll l=0, r=n-1;
  while(r-l>=3) {
    ll m = (l+r)/2, gl=0, gr=0;
    rep2(i, l, m) gl = __gcd(gl, a[i]);
    rep2(i, m+1, r) gr = __gcd(gr, a[i]);
    if(gl > gr) l=m+1;
    else r=m;
  }

  ll g1=0, g2=0, g3=0;
  rep(i, n) {
    if(i != l) g1 = __gcd(g1, a[i]);
    if(i != l+1) g2 = __gcd(g2, a[i]);
    if(i != l+2) g3 = __gcd(g3, a[i]);
  }
  cout << max(max(g1, g2), g3) << newl;
  return 0;
}