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
  int n;
  n = s.length();

  if(s[n-1] != '0'){
    cout << -1 << endl;
    return 0;
  }
  if(s[0] == '0'){
    cout << -1 << endl;
    return 0;
  }

  for(int i = 0; i < n/2; i++){
    if(s[i] != s[n-2-i]){
      cout << -1 << endl;
      return 0;
    }
  }
  // あとは0, ..., n-2まで考えればよくて、
  // 具体的には n/2までかんがえればよい
  vector<vector<int>> G(n);
  int now = 0;
  int cnt = 0;
  for(int i = 0; i < n/2; i++){
    if(s[i] == '1'){
      G[now].push_back(i+1);
      G[i+1].push_back(now);
      now = i+1;
      cnt++;
    }else{
      G[now].push_back(i+1);
      G[i+1].push_back(now);
      cnt++;
    }
  }
  int hub = now;
  for(int i = n/2+1; i < n; i++){
    G[hub].push_back(i);
    G[i].push_back(hub);
  }

  rep(i, n){
    rep(j, G[i].size()){
      int st = i;
      int go = G[i][j];
      if(st < go){
        cout << st+1 << " " << go+1 << endl;
      }
    }
  }

  return 0;
}
