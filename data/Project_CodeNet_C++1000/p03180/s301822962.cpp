/*
 * Author : Andrew J
*/
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
using ll = long long;
using ii = pair <ll , ll>;
void in(ll &x);
const ll N = 16;
ll n;
ll value[1 << N];
vector < vector <ll> > grid, dp;

void precompute() {
  for (ll mask = 0 ; mask < (1 << n) ; mask++) {
    for (ll i = 0 ; i < n ; i++) {
      for (ll j = i + 1 ; j < n ; j++) {
        if ((mask & (1 << i)) && (mask & (1 << j))) {
          value[mask] += grid[i][j];
        }
      }
    }
  }
}

ll notMask(ll mask) {
  ll sol = 0;
  for (ll i = 0 ; i < n ; i++) {
    if (mask & (1 << i)) {

    } else {
      sol += (1 << i);
    }
  }
  return sol;
}

ll f(ll cur , ll mask) {
  if (__builtin_popcount(mask) == n) return 0;
  if (cur >= n) return 0;

  ll &sol = dp[cur][mask];
  if (sol != -1) return sol;

  sol = 0;
  ll others = notMask(mask);
  for (ll i = others ; i > 0 ; i = (i - 1) & others) {
    sol = max(sol , f(cur + 1 , mask | i) + value[i]);
  }

  return sol;
}

int main() {
  in(n);
  grid.resize(n + 1 , vector <ll> (n + 1 , 0));
  for (ll i = 0 ; i < n ; i++) {
    for (ll j = 0 ; j < n ; j++) {
      in(grid[i][j]);
    }
  }

  precompute();

  dp.resize(n + 1 , vector <ll> (1 << n , -1));
  printf("%lld\n" , f(0 , 0));
  return 0;
}

void in(ll &x){
	bool neg = false;
	register ll c;
	x = 0;
	c = getchar();
	if(c == '-'){
		neg = true;
		c = getchar();
	}
	for (; c > 47 && c < 58; c = getchar())
	x = (x << 1) + (x << 3) + c - 48;
	if (neg) x *= -1;
}
