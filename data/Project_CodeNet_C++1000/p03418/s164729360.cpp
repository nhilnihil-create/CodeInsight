#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

ll N, K;

ll f(ll n){
  ll res = 0;
  ll a = N/n;
  ll b = 0;
  if(N%n != 0){
    if(N%n >= K && K != 0) b = N%n - K + 1;
    if(N%n >= K && K == 0) b = N%n - K;
  }
  res += a*(n-K) + b;
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> K;
  ll ans = 0;
  for(ll i = K+1; i <= N; i++){
    ans += f(i);
  }
  cout << ans << endl;
}