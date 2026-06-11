#include <iostream>
#include <vector>
#include <cmath>
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; i++)
using namespace std;

ll gcd(ll a, ll b){
  if (b == 0) return a;
  if (a % b == 0) return b;
  else return gcd(b, a % b);
}

int main(){
  ll n;
  cin >> n;
  vector<ll> a(n), L(n+1), R(n+1);
  rep(i, n) cin >> a[i];
  L[0] = 0, R[n] = 0;
  rep(i, n){
    L[i+1] = gcd(L[i], a[i]);
    R[n-i-1] = gcd(R[n-i], a[n-i-1]);
  }
  ll ans = 1;
  rep(i, n){
    ans = max(ans, gcd(L[i], R[i+1]));
  }
  cout << ans << endl;
  
  return 0;
}