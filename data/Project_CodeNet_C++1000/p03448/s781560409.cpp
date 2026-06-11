#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll A, B, C, X; cin >> A >> B >> C >> X;
  ll ans = 0;
  REPLL(i, A+1){
    REPLL(j, B+1){
      REPLL(k, C+1){
        if(X == i*500 + j*100 + k*50) ans++;
      }
    }
  }
  cout << ans << endl;
}