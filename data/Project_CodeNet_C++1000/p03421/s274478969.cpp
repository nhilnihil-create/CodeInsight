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

  ll N, A, B;
  cin >> N >> A >> B;

  if( B > (N-A)+1 || A * B < N){
    cout << -1 << endl;
  }else{
    
    vector<ll> T;
    ll S = N - A;
    ll cur = N;
    for(int i = 0; i < A ; i++){
      ll num = min(B-1, S) + 1;
      S -= num - 1;
      for(int j = 0; j < num; j++){
        T.push_back(cur-num+1+j);
      }
      cur -= num;
    }
    reverse(T.begin(), T.end());
    for(int i = 0; i < N; i++){
      cout << T[i] << " ";
    }
    cout << endl;
  }

  return 0;
}
