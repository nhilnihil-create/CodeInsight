#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
constexpr char ln = '\n';

const int mx=100010;
const ll mod=1e9+7;

ll gcd(ll a, ll b){ return b ? gcd(b,a%b):a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }

int main(){
  int n,m;
  cin >> n >> m;
  vector<pair<ll,ll>> a;
  rep(i,n){
    ll x; cin >> x;
    a.emplace_back(x,1);
  }
  rep(T,m){
    ll b,c; cin >> b >> c;
    a.emplace_back(c,b);
  }

  sort(a.rbegin(),a.rend());
  int cnt = n;
  ll ans = 0;
  rep(i,n+m){
    if(a[i].S<cnt){
      ans += a[i].F*a[i].S;
      cnt -= a[i].S;
    } else {
      ans += a[i].F*cnt;
      break;
    }
  }
  cout << ans << ln;
  return 0;
}