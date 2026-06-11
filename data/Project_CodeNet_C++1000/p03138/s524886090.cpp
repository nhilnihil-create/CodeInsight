#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC117 D - XXOR
// 2進数の桁数

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, K; cin >> N >> K;
  vector<ll> A(N);
  REP(i, N){
    cin >> A[i];
  }
  bool flag = false;
  bitset<40> a(0);
  REP(i, 40){
    bitset<40> bsK(K);
    ll cnt = 0;
    REP(j, N){
      bitset<40> bsA(A[j]);
      if(bsA[39-i] == 1) cnt++;
    }
    if(bsK[39-i] == 1 || flag == true){
      if(cnt*2 < N){
        a.set(39-i);
      }else{
        flag = true;
      }
    }
  }
  ll res = a.to_ullong();
  ll ans = 0;
  REP(i, N){
    ans += A[i]^res;
  }
  cout << ans << endl;
}