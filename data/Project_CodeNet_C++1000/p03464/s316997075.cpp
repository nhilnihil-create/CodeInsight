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

  int k;
  cin >> k;

  vector<ll> A(k);
  rep(i, k) cin >> A[i];

  reverse(A.begin(), A.end());

  ll min_val = 2;
  ll max_val = 2;

  rep(i, k){
    
    ll a = A[i];
    min_val = (min_val + a - 1) / a * a;
    max_val = max_val / a * a;

    if(max_val < min_val){
      cout << -1 << endl;
      return 0;
    }

    max_val = max_val + a-1;

  }

  cout << min_val << " " << max_val << endl;

  

  return 0;
}
