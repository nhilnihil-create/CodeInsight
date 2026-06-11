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

  ll N, Z, W;
  cin >> N >> Z >> W;
  vector<ll> a(N);
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }

  if(N == 1){
    cout << abs(a[0] - W) << endl;
  }else{
    cout << max(abs(a[N-1]-W), abs(a[N-1]-a[N-2])) << endl;
  }

  return 0;
}
