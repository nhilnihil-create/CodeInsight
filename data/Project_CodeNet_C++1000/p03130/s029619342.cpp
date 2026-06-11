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

  vector<int> a(3), b(3);

  rep(i, 3){
    cin >> a[i] >> b[i];
  }

  bool ok = false;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        if(i==j || j==k || i==k) continue;

        // i-> j -> kの順
        if(b[i]==a[j] && b[j]==a[k]){
          ok = true;
          break;
        }
        if(b[i]==a[j] && b[j]==b[k]){
          ok = true;
          break;
        }
        if(b[i]==b[j] && a[j]==a[k]){
          ok = true;
          break;
        }
        if(b[i]==b[j] && a[j]==b[k]){
          ok = true;
          break;
        }
        if(a[i]==a[j] && b[j]==a[k]){
          ok = true;
          break;
        }
        if(a[i]==a[j] && b[j]==b[k]){
          ok = true;
          break;
        }
        if(a[i]==b[j] && a[j]==a[k]){
          ok = true;
          break;
        }
        if(a[i]==b[j] && a[j]==b[k]){
          ok = true;
          break;
        }


      }
    }
  }

  if(ok){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }

  return 0;
}
