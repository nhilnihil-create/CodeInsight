#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using ld = long double;
long double const pi = std::acos(-1.0L);


int main() {
  ll a, b;
  cin >> a >> b;
  int k;
  cin >> k;
  for(ll i = a; i <= min(a+k-1,b); ++i){
    cout << i << endl;
  }
  vector<ll> s(k);
  for(ll i = max(b-k+1,a+k); i <= b; ++i){
    cout << i << endl;
  }
  return 0;
}