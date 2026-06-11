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

ll getsub(vector<ll> a){

  // 昇順の数列が入力される
  // 1始まりでないとだめ

  // check
  int n = a.size();

  rep(i, n-1){
    if(a[i+1]-a[i] > 1){
      return -1;
    }
  }

  ll ret = 0;
  ret += a[n-1];
  for(int i = n-1; i > 0; i--){
    if(a[i] == a[i-1]){
      ret += a[i];
    }
  }

  return ret;

}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<ll> A(N);
  rep(i, N) cin >> A[i];

  if(A[0] != 0){
    cout << -1 << endl;
    return 0;
  }

  ll ans = 0;
  vector<ll> tmp;
  tmp.push_back(A[1]);
  rep(i,1, N-1){
    if(A[i] <= A[i+1]){
      tmp.push_back(A[i+1]);
    }else{
      
      ll tans = getsub(tmp);
      if(tans == -1){
        cout << -1 << endl;
        return 0;
      }

      ans += tans;

      vector<ll> t;
      t.push_back(A[i+1]);
      tmp = t;

    }
  }

  ll tans = getsub(tmp);
  if(tans==-1){
    cout << -1 << endl;
    return 0;
  }

  ans += tans;

  cout << ans << endl;

  return 0;
}
