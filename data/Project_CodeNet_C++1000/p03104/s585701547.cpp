#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

ll x(ll c){
  if(c % 4 == 0) return c;
  if(c % 4 == 1) return 1;
  if(c % 4 == 2) return c + 1;
  return 0;
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << (x(a - 1) ^ x(b)) << endl;
}
