#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC100 B
// 2020.05.25

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll D, N; cin >> D >> N;
  ll ans;
  if(N != 100){
    ans =  N*pow(100, D);
  }else{
    ans = 101*pow(100, D);
  }
  cout << ans << endl;
}