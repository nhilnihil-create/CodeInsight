#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll tri(ll x) {
  return x*x*x;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  
  ll n, k;
  cin >> n >> k;
  
  if(k % 2 == 1) {
    cout << tri(n/k) << "\n";
    return 0;
  }
  else {
    cout << tri(n/k) + tri(n/(k/2) - (n/k)) << "\n";
    return 0;
  }
}