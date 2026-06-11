#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pl;
typedef queue<ll> ql;
typedef set<ll> sl;
typedef vector<ll> vl;
#define rep(i, n) for(ll i = 0; i < ll(n); i++)
#define rep2(i, n) for(ll i = 1; i <= ll(n); i++)
//#define rep(i, k, n) for(ll i = k-1; i < ll(n); i++)
//#define rep2(i, k, n) for(ll i = k; i <= ll(n); i++)
#define all(v) v.begin(), v.end()
bool chmin(ll &a, ll &b) {if(b < a) {a = b; return 1;} return 0;}
bool chmax(ll &a, ll &b) {if(b > a) {a = b; return 1;} return 0;}
const ll INF = 999999999999999;
const ll MOD = 1000000007;
const ll MAX = 500010;
ll num, M, N, ans=0, count=0;

sl move(sl set, ll m, ll flg) {
  sl S;
  for(ll i: set) {
    S.insert(i+m);
    if(flg>=1) S.insert(i-m);
  }
  return S;
}

int main() {
  string s;
  cin >> s;
  ll x, y, m=1, flg=0;
  cin >> x >> y;
  
  sl set_x={0}, set_y={0};
  rep(i, s.size()) {
    if(s[i] == 'T') flg++;
    else if(s[i] == 'F' && s[i+1] == 'F') m++;
    else {
      if(flg%2==0) set_x = move(set_x, m, flg);
      else set_y = move(set_y, m, flg);
      m=1;
    }
  }
  
  for(ll i: set_x) if(x==i) ans++;
  for(ll i: set_y) if(y==i) ans++;
  
  if(ans==2) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
