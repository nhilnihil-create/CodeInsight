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

const ll MOD = 1e9+7;

ll dp[3010][3010];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  string s;
  cin >> s;

  rep(i, N+1){
    rep(j, N){
      dp[i][j] = 0;
    }
  }

  rep(i, N){
    dp[0][i] = 1;
  }

  rep(i, N-1){

    vector<ll> dp_sum(N+1, 0LL);
    dp_sum[0] = 0LL;
    rep(j, N){
      dp_sum[j+1] = (dp_sum[j] + dp[i][j]) % MOD;
    }

    rep(j, N){
      if(s[i] == '<'){
        if(N-i-1 < j+1) continue;
        dp[i+1][j] = (dp_sum[N-i] + MOD - dp_sum[j+1]) % MOD;
      }else{
        dp[i+1][j] = (dp_sum[j+1] + MOD - dp_sum[0]) % MOD;
      }
    }
  }

  cout << dp[N-1][0] << endl;

  return 0;
}
