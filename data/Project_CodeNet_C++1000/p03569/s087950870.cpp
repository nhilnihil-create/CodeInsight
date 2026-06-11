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

  string s;
  cin >> s;

  string t = "";

  rep(i, s.length()){
    if(s[i] != 'x'){
      t += s[i];
    }
  }

  // check
  int m = t.length();
  rep(i, t.length()/2){
    if(t[i] != t[m-1-i]){
      cout << -1 << endl;
      return 0;
    }
  }

  vector<int> cntx((m+1)/2);

  int cnt = 0;
  int now = 0;
  while(cnt < (m+1)/2){

    if(s[now] == 'x'){
      cntx[cnt]++;
      now++;
    }else{
      cnt++;
      now++;
    }
  }

  now = s.length()-1;
  cnt = 0;

  while(cnt < (m+1)/2){
    if(s[now] == 'x'){
      cntx[cnt]--;
      now--;
    }else{
      cnt++;
      now--;
    }
  }

  int ans = 0;
  rep(i, cntx.size()){
    ans += abs(cntx[i]);
  }

  cout << ans << endl;

  return 0;
}
