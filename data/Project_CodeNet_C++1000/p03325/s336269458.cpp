#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC100 C
// 2020.05.25
ll func(ll n){
  ll res = 0;
  while(n%2 == 0){
    n /= 2;
    res++;
  }
  return res;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N; cin >> N;
  ll ans = 0;
  REP(i, N){
    ll tmp; cin >> tmp;
    if(tmp%2 == 0) ans += func(tmp);
  }
  cout << ans << endl;
}