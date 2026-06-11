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

  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  bool is_equal = true;
  for(int i = 0; i < N; i++){
    cin >> A[i] >> B[i];
    if(A[i] != B[i]) is_equal = false;
  }

  int max_ind = 0;
  ll min_B = 1e14;
  for(int i = 0; i < N; i++){
    if(A[i] > B[i]){
      chmin(min_B, B[i]);
    }
  }

  ll ans = 0;
  for(int i = 0; i < N; i++){
    ans += A[i];
  }
  ans -= min_B;

  if(is_equal){
    cout << 0 << endl;
  }else{
    cout << ans << endl;
  }
  
  return 0;
}
