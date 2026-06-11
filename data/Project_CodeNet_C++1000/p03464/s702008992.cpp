#include <bits/stdc++.h>
using namespace std;

// #define int long long
#define rep(i, n) for (int i = (int)(0); i < (int)(n); ++i)
#define reps(i, n) for (int i = (int)(1); i <= (int)(n); ++i)
#define rrep(i, n) for (int i = ((int)(n)-1); i >= 0; i--)
#define rreps(i, n) for (int i = ((int)(n)); i > 0; i--)
#define irep(i, m, n) for (int i = (int)(m); i < (int)(n); ++i)
#define ireps(i, m, n) for (int i = (int)(m); i <= (int)(n); ++i)
#define SORT(v, n) sort(v, v + n);
#define REVERSE(v, n) reverse(v, v+n);
#define vsort(v) sort(v.begin(), v.end());
#define all(v) v.begin(), v.end()
#define mp(n, m) make_pair(n, m);
#define cout(d) cout<<d<<endl;
#define coutd(d) cout<<std::setprecision(10)<<d<<endl;
#define cinline(n) getline(cin,n);
#define replace_all(s, b, a) replace(s.begin(),s.end(), b, a);
#define PI (acos(-1))
#define FILL(v, n, x) fill(v, v + n, x);
#define sz(x) int(x.size())

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vs = vector<string>;
using vpll = vector<pair<ll, ll>>;
using vtp = vector<tuple<ll,ll,ll>>;
using vb = vector<bool>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const ll INF = 1e15;
const int MOD = 1e9+7;
const ll LINF = 1e18;

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll ngcd(vector<ll> a) {
  ll res = a[0];
  for(ll i=1; i<a.size() && res!=1; i++) res = gcd(a[i], res);
  return res;
}
ll nlcm(vector<ll> a){
  ll res = a[0];
  for(ll i=1; i<a.size(); i++) res = lcm(a[i], res);
  return res;
}
bool is_prime(ll n) {
  if(n < 2) return false;
  for (ll i = 2; i * i <= n; i++) if (n % i == 0) return false;
  return true;
}
ll digsum(ll n) {
  ll res=0;
  while(n) res += n%10, n /= 10;
  return res;
}
ll digcnt(ll n){
  ll res=0;
  while(n) res++, n /= 10;
  return res;
}
set<ll> divisor(ll n) {
  set<ll> res;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.insert(i);
      if (i != n / i) res.insert(n / i);
    }
  }
  return res;
}
map<ll, ll> prime_factor(ll n) {
  map<ll, ll> res;
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) ++res[i], n /= i;
  }
  if (n != 1) res[n] = 1;
  return res;
}

signed main()
{
  cin.tie( 0 ); ios::sync_with_stdio( false );
  ll k; cin>>k;
  vll a(k);
  rep(i,k) cin>>a[i];
  reverse(all(a));
  
  ll l=2, r=2; // ラウンドi直後の最小と最大を保持する
  rep(i,k){
    l=(l+a[i]-1)/a[i]; // [l,r]においてa_iの倍数である最小とは ceil(l/a_i)*a_i
    r=r/a[i]; // 最大は floor(r/a_i)*a_i
    // ceil(l/a_i) <= floor(r/a_i) の関係が成り立たない場合
    // つまり、[l,r]においてa_iの倍数が存在しない場合、そのラウンドから直後の状態は作れない
    if(l>r){
      cout<<-1<<endl;
      return 0;
    }
    l=l*a[i];
    r=r*a[i]+a[i]-1;
  }
  cout<<l<<" "<<r<<endl;
}