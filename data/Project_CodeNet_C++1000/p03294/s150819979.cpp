#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC103 C - Modulo Summation
// 2020.06.12

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N; cin >> N;
  ll ans = 0;
  REPLL(i, N){
    ll a; cin >> a; a--;
    ans += a;
  }
  cout << ans << endl;
}