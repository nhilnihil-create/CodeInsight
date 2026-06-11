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
  vector<int> a(N);
  for(int i = 0; i < N; i++){
    cin >> a[i];
  }

  bool absmax_pl = true;
  int abs_max = 0;
  int max_ind = 0;
  for(int i = 0; i < N; i++){
    if(abs_max <= abs(a[i])){
      abs_max = abs(a[i]);
      if(a[i] >= 0){
        absmax_pl = true;
      }else{
        absmax_pl = false;
      }
      max_ind = i;
    }
  }

  if(absmax_pl){
    // 正だったら
    cout << 2 * (N-1) << endl;
    for(int i = 0; i < N; i++){
      if(i != max_ind){
        cout << (max_ind+1) << " " << (i+1) << endl;
      }
    }

    // 下から
    for(int i = 0; i < N-1; i++){
      cout << i+1 << " " << i+2 << endl; 
    }

  }else{
    // 負だったら
    cout << 2 * (N-1) << endl;
    for(int i = 0; i < N; i++){
      if(i != max_ind){
        cout << (max_ind+1) << " " << (i+1) << endl;
      }
    }

    for(int i = N; i > 1; i--){
      cout << i << " " << (i-1) << endl;
    }
  }



  return 0;
}
