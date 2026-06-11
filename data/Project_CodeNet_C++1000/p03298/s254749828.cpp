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

map<tuple<string, string, string>, ll> mp;

ll dfs(string c, string a, string b){

  if(mp.find(make_tuple(c, a, b)) != mp.end()){
    return mp[make_tuple(c, a, b)];
  }

  ll ret = 0;
  if(c.length()==1 && a.length()==1 && c[0]==a[0]){
    return 1;
  }
  if(c.length()==1 && b.length()==1 && c[0]==b[0]){
    return 1;
  }

  if(a.length()>0 && c[0] == a[0]){
    ret += dfs(c.substr(1, c.length()-1), a.substr(1, a.length()-1), b);
  }
  if(b.length()>0 && c[0] == b[0]){
    ret += dfs(c.substr(1, c.length()-1), a, b.substr(1, b.length()-1));
  }

  return mp[make_tuple(c, a, b)] = ret;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  string s;
  cin >> s;
  string c = s.substr(N, s.length()-N);
  reverse(c.begin(), c.end());

  ll ans = 0;
  for(int bit = 0; bit < (1<<N); bit++){
    string a = "";
    string b = "";

    rep(i, N){
      if(bit & (1<<i)){
        a += s[i];
      }else{
        b += s[i];
      }
    }

    ans += dfs(c, a, b);

  }

  cout << ans << endl;

  return 0;
}
