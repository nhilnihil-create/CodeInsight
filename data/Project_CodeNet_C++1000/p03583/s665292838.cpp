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

  ll N;

  cin >> N;
  ll ans_h, ans_n, ans_w;
  ans_h = 0;
  ans_n = 0;
  ans_w = 0;
  for(int h = 1; h <= 3500; h++){
    for(int n = 1; n <= 3500; n++){
      if((((4*h*n) - N *(n+h)) > 0) && (((N*h*n) % ((4*h*n) - N *(n+h))) == 0) && ((N*h*n) / ((4*h*n) - N *(n+h)) <= 3500)){
        ans_h = h;
        ans_n = n;
        // cout << (N*h*n) << " " << ((4*h*n) - N *(n+h)) << endl;
        ans_w = (N*h*n) / ((4*h*n) - N *(n+h));
        break;
      }
    }
  }

  cout << ans_h << " " << ans_n << " " << ans_w << endl;

  return 0;
}
