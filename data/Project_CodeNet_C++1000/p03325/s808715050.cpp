#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll power2(ll a) {
  ll res = 0;
  while (a % 2 == 0) {
    res++;
    a /= 2;
  }
  
  return res;
}

int main() {
  int N;
  cin >> N;
  
  ll ans = 0;
  
  for (int i = 0; i < N; i++) {
    ll x;
    cin >> x;
    
    ans += power2(x);
  }
  
  cout << ans << endl;
  
}