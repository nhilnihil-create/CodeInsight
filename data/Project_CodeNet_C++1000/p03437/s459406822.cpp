#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define REPLL(i, n) for (ll i = 0; i < (ll)(n); i++)
using namespace std;
template<class T>inline bool chmax(T &a, const T &b){if(a < b){a = b; return 1;}return 0;}
template<class T>inline bool chmin(T &a, const T &b){if(a > b){a = b; return 1;}return 0;}
typedef long long ll;

//AtCoder Petrozavodsk Contest 001 A - Two Integers

ll gcd(ll n, ll m){
  if(m == 0) return n;
  return gcd(m, n%m);
}

ll lcm(ll n, ll m){
  return n / gcd(n, m) * m;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll X, Y; cin >> X >> Y;
  ll tmp = lcm(X, Y);
  if(tmp == X){
    cout << -1 << endl;
  }else{
    cout << X*(tmp/X-1) << endl;
  }

}