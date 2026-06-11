#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
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

  ll N, K;
  cin >> N >> K;

  ll ans = 0;
  for(ll d = 1; K + d <= N; d++){
    ans += N / (K+d) * d + max(0LL, N % (K+d)-K+1);
  }

  if(K == 0){
    cout << N * N << endl;
  }else{
    cout << ans << endl;
  }
  
  return 0;
}
