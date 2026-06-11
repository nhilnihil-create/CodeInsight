#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC127 A - Ferris Wheel
// 2020.07.04

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  int A, B; cin >> A >> B;
  int ans = B;
  if(A <= 12 && A >= 6){
    ans = B/2;
  }else if(A <= 5){
    ans = 0;
  }
  cout << ans << endl;
}