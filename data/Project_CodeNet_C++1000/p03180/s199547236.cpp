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

int N, A[16][16];
ll dp[1 << 16];
ll cost[1 <<16];

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;

  rep(i, N){
    rep(j, N){
      cin >> A[i][j];
    }
  }

  for(int mask = 0; mask < (1 << N); mask++){
    rep(i, N){
      for(int j = i+1; j < N; j++){
        if((mask & (1 << i)) && (mask & (1 << j))) cost[mask] += A[i][j];
      }
    }
  }

  for(int mask = 0; mask < (1 << N); mask++){
    for(int mask2 = mask; mask2 > 0; mask2 = (mask2 - 1) & mask){
      ll next = dp[mask - mask2] + cost[mask2];
      chmax(dp[mask], next);
    }
  }

  cout << dp[(1<<N) - 1] << endl;

  return 0;
}
