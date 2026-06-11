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

  int n, q;
  cin >> n >> q;
  string s = "a";
  string ss;

  cin >> ss;
  s += ss;
  s += "a";

  int left = 0;
  int right = n+1;

  vector<char> t(q), L(q);
  rep(i, q){
    cin >> t[i] >> L[i];
  }

  for(int i = q-1; i >= 0; i--){

    // rightの処理
    if(L[i] == 'L' && s[right] == t[i]){
      right = min(n+1, right+1);
    }
    if(L[i] == 'R' && s[right-1] == t[i]){
      right = max(1, right-1);
    }

    if(L[i] == 'L' && s[left+1] == t[i]){
      left = min(n, left+1);
    }

    if(L[i] == 'R' && s[left] == t[i]){
      left = max(0, left - 1);
    }

  }

  if(right <= left){
    cout << 0 << endl;
  }else{
    cout << right - left - 1 << endl;
  }

  return 0;
}
