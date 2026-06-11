#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

// ABC117 A - Entrance Examination
// 2020.07.01

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  double T, X; cin >> T >> X;
  double ans = T/X;
  cout << fixed << setprecision(10) << ans << endl;;
}