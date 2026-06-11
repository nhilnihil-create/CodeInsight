#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main() {
  
  ll A, B;
  cin >> A >> B;
  ll ans = 0;
  ll N = 50; // 2^N > 10^12 を超える適当なN
  
  ll x = 2; // 2の累乗
  
  ans = (((B+1) / 2) - (A/2)) % 2; // 1の位
  
  for (int i = 1; i < N; i++) {
    ll a = 0, b = 0; 
    if (A % (x*2) >= x) {
      a = x - (A % x);
    }
    if (B % (x*2) >= x) {
      b = B % x + 1;
    }
    if ((a+b) % 2) {
      ans += x;
    }
    x *= 2;
  }
  cout << ans << endl;
}