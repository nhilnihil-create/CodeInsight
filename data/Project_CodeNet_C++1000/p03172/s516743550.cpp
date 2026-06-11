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
const ll N = 105;
const ll K = 1e5 + 10;
const ll M = 1e9 + 7;
ll n, k;
ll a[N], dp[N][K], ps[N][K];

ll subs(ll a , ll b) {
  return (((a % M) - (b % M)) + 2 * M) % M;
}

ll add(ll a , ll b) {
  return ((a % M) + (b % M)) % M;
}

ll rsum(ll l , ll r , ll idx) {
  if (l > r) return 0;
  return subs(ps[idx][r] , ps[idx][l - 1]);
}

int main() {
  scanf("%lld%lld" , &n , &k);
  for (ll i = 1 ; i <= n ; i++) {
    scanf("%lld" , &a[i]);
  }
  for (ll cur = 0 ; cur <= n ; cur++) {
    for (ll rem = 0 ; rem <= k ; rem++) {
      ll &sol = dp[cur][rem];
      if (cur == 0) {
        sol = (rem == 0);
      } else {
        sol = rsum(rem - min(rem , a[cur]) , rem , cur - 1);
      }
      if (rem) {
        ps[cur][rem] = add(ps[cur][rem - 1] , sol);
      } else {
        ps[cur][rem] = sol;
      }
    }
  }
  printf("%lld\n" , dp[n][k]);
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
