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

  int H, W, N;
  cin >> H >> W >> N;

  int sr, sc;
  cin >> sr >> sc;

  string s, t;
  cin >> s >> t;

  // L, Rについて
  int r = W;
  int l = 1;

  if(s[N-1]=='R'){
    r--;
  }
  if(s[N-1]=='L'){
    l++;
  }

  for(int i = N-2; i >= 0; i--){

    // 青木くん

    if(t[i]=='L'){
      r = min(r+1, W);
    }
    if(t[i]=='R'){
      l = max(l-1, 1);
    }

    if(s[i]=='R'){
      r--;
    }
    if(s[i]=='L'){
      l++;
    }

    if(l > r){
      cout << "NO" << endl;
      return 0;
    }
    if(l <= 0){
      cout << "NO" << endl;
      return 0;
    }
    if(r >= W+1){
      cout << "NO" << endl;
      return 0;
    }

  }
  if(sc < l || r < sc){
    cout << "NO" << endl;
    return 0;
  }

  r = H;
  l = 1;

  if(s[N-1]=='D'){
    r--;
  }
  if(s[N-1]=='U'){
    l++;
  }

  for(int i = N-2; i >= 0; i--){

    // 青木くん

    if(t[i]=='U'){
      r = min(r+1, H);
    }
    if(t[i]=='D'){
      l = max(l-1, 1);
    }

    if(s[i]=='D'){
      r--;
    }
    if(s[i]=='U'){
      l++;
    }

    if(l > r){
      cout << "NO" << endl;
      return 0;
    }
    if(l <= 0){
      cout << "NO" << endl;
      return 0;
    }
    if(r >= H+1){
      cout << "NO" << endl;
      return 0;
    }

  }
  if(sr < l || r < sr){
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;

  return 0;
}
