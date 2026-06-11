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

int s[310][310];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  
  rep(i, n){
    string t;
    cin >> t;
    rep(j, n){
      s[i][j] = int(t[j] - 'a');
    }
  }

  int ans = 0;

  rep(k, n){

    bool ok = true;
    rep(i, n){
      rep(j, i+1, n){

        int i1 = (i + k) % n;
        int j1 = j;

        int i2 = (j + k) % n;
        int j2 = i;

        if(s[i1][j1] != s[i2][j2]){
          ok= false;
        }

      }
    }
    if(ok){
      ans += n;
    }
  }

  cout << ans << endl;

  return 0;
}
