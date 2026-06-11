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
  vector<ll> A(N);

  for(int i = 0; i < N; i++){
    cin >> A[i];
  }

  multiset<ll> ms;
  for(int i = 0; i < N; i++){
    ms.insert(A[i]);
  }

  sort(A.begin(), A.end(), greater<ll>());

  ll ans = 0;
  for(int i = 0; i < N; i++){
    ll base = 1;
    while(base <= A[i]){
      base = base * 2;
    }
    // baseをつくる
    // setから取り除く(なぜならばもう使われることはない)
    auto itr = ms.find(A[i]);
    if(itr != ms.end()){
      ms.erase(itr);
      auto nitr = ms.find(base - A[i]);
      if(nitr != ms.end()){
        ms.erase(nitr);
        ans++;
      }
    }
  }

  cout << ans << endl;

  return 0;
}
