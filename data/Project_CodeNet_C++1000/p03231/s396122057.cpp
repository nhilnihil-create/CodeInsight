#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define Rep(i, a, b) for(int i = a; i <= b; i++)
#define _GLIBCXX_DEBUG
#define Vl vector<ll>
#define Vs vector<string>
#define Vp vector<pair<ll, ll>>
#define ll long long
#define ALL(v) (v).begin(),(v).end()
#define endl "\n"
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define co(x) cout << x << endl;
using namespace std;  
const double pi = acos(-1.0);
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;


//最大公約数
ll gcd(ll a, ll b){
  if (a%b == 0) {
    return(b);
  } else {
    return(gcd(b, a%b));
  }
}

//最小公倍数
ll lcm(ll a, ll b){
  return a / gcd(a, b) * b;
}

int main() {
  ll n, m; cin >> n >> m;
  string s, t; cin >> s >> t;
  ll a = lcm(n, m);
  vector<char> v = {}, w = {};
  for(int i = 0; i < n; i += a/m){
    v.push_back(s[i]);
  }
  for(int i = 0; i < m; i += a/n){
    w.push_back(t[i]);
  }
  rep(i, 0, v.size()){
    if(v[i] != w[i]){
      cout << -1 << endl;
      return 0;
    }
  }
  cout << a << endl;
  


  return 0;
}