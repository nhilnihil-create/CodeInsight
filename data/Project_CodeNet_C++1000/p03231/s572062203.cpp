#include <bits/stdc++.h>

using namespace std;
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)

typedef long long ll;
typedef pair<ll, ll> P;
const ll INF = 1LL<<60;

ll gcd(ll a, ll b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

ll modpow(ll a, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;

  string s, t;
  cin >> s >> t;

  if(n < m){
    swap(n, m);
    swap(s, t);
  }

  if(n % m != 0){

    ll g = gcd(n, m);

    ll ret = n / g * m;

    n /= g;
    m /= g;
    bool ok = true;
    rep(i, g){
      if(s[i*n] != t[i*m]) ok = false;
    }

    if(ok) cout << ret << endl;
    else cout << -1 << endl;


  }else{

    ll k = n / m;
    bool ok = true;
    for(int i = 0; i < m; i++){
      if(s[i*k] != t[i]){
        ok = false;
        break;
      }
    }

    if(ok){
      cout << n << endl;
      return 0;
    }else{
      cout << -1 << endl;
      return 0;
    }



  }

  return 0;
}
