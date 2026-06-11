#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using ll = long long;

ll tenpow(ll n) {
  ll tmp = 1; REP(i, n) tmp *= 10;
  return tmp;
}

int main() {
  ll n; cin >> n;
  ll top = n; ll digit = 1;
  while (top > 9) {
    top /= 10;
    ++digit;
  }
  
  cout << ((n + 1) % tenpow(digit - 1) == 0 ?
           top + 9 * (digit - 1):
           top - 1 + 9 * (digit - 1)) << endl;
  
  return 0;
}