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
const ll N = 21;
const ll M = 1e9 + 7;
ll n;
ll grid[N][N], dp[N + 5][1 << N];

ll f(ll cur , ll mask) {
  if (cur >= n) return __builtin_popcount(mask) == n;
  ll &sol = dp[cur][mask];
  if (sol != -1) return sol;
  sol = 0;
  for (ll i = 0 ; i < n ; i++) {
    if (mask & (1 << i)) {

    } else {
      if (grid[i][cur]) {
        (sol += f(cur + 1 , mask | (1 << i))) %= M;
      }
    }
  }
  return sol;
}

int main() {
  in(n);
  for (ll i = 0 ; i < n ; i++) {
    for (ll j = 0 ; j < n ; j++) {
      in(grid[i][j]);
    }
  }
  // for (ll cur = 0 ; cur <= n ; cur++) {
  //   for (ll mask = (1 << n) - 1 ; mask >= 0 ; mask--) {
  //     ll &sol = dp[cur][mask];
  //     if (cur == 0) {
  //       sol = __builtin_popcount(mask) == n;
  //     } else {
  //       for (ll i = 0 ; i < n ; i++) {
  //         if (mask & (1 << i)) {
  //
  //         } else {
  //           if (grid[i][cur - 1]) {
  //             sol += dp[cur - 1][mask | (1 << i)];
  //           }
  //         }
  //       }
  //     }
  //   }
  // }
  // printf("%d\n" , dp[n][0]);
  memset (dp , -1 , sizeof dp);
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