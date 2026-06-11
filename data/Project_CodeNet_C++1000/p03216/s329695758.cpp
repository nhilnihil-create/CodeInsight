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

int n;
string s;

ll solve(int k){

  ll cnt_d = 0;
  ll cnt_m = 0;
  ll cnt_dm = 0;
  ll ret = 0;
  rep(i, n){
    
    // 1
    if(i - k >= 0){
      if(s[i-k]=='D'){
        cnt_d--;
        cnt_dm -= cnt_m;
      }
      if(s[i-k]=='M'){
        cnt_m--;
      }
    }

    // 2
    if(s[i] == 'D'){
      cnt_d++;
    }
    if(s[i]=='M'){
      cnt_m++;
      cnt_dm += cnt_d;
    }

    if(s[i]=='C'){
      ret += cnt_dm;
    }
  }

  return ret;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> s;

  int Q;
  cin >> Q;
  vector<ll> ans(Q);

  rep(q, Q){
    int k;
    cin >> k;
    ans[q] = solve(k);

  }

  rep(q, Q){
    cout << ans[q] << endl;
  }

  return 0;
}
