#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define bg begin()
#define en end()

using namespace std;

typedef long long ll;

ll N, K;

ll g(ll n, ll k) {
  if (k == 0) return n*n;
  ll res = 0;
  for (int i = k+1; i <= n; i++) {
    ll q = n/i, r = n%i;
    res += q * (i-k);
    if (r != 0 && r >= k) res += r-k+1;
  }
  return res;
}

int main() {
  
  scanf("%lld %lld", &N, &K);
  
  printf("%lld\n", g(N, K));
  
  return 0;
}
 
