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
const ll N = 2e5 + 10;
const ll INF = 1e18;
ll n;
ll height[N], beauty[N], dp[N], tree[N * 8], li[N];

ll rangeMax(ll idx , ll l , ll r , ll a , ll b) {
  if (r < a || l > b) return -INF;
  if (a <= l && r <= b) return tree[idx];
  ll mid = (l + r) / 2;
  return max(
    rangeMax(idx * 2 , l , mid , a , b),
    rangeMax(idx * 2 + 1 , mid + 1 , r , a , b)
  );
}

void update(ll idx , ll l , ll r , ll x , ll val) {
  if (l == x && r == x) {
    tree[idx] = val;
    return;
  }
  if (l > x || r < x) return;
  ll mid = (l + r) / 2;
  update(idx * 2 , l , mid , x , val);
  update(idx * 2 + 1 , mid + 1 , r , x , val);
  tree[idx] = max(tree[idx * 2] , tree[idx * 2 + 1]);
}

void inputAndInit() {
  in(n);
  for (ll i = 1 ; i <= n ; i++) {
    in(height[i]);
    li[i] = height[i];
  }
  sort(li + 1 , li + 1 + n);
  for (ll i = 1 ; i <= n ; i++) {
    in(beauty[i]);
  }
  for (ll i = 1 ; i <= n ; i++) {
    dp[i] = beauty[i];
  }
}

void computeDP() {
  for (ll cur = 1 ; cur <= n ; cur++) {
    ll lb = (ll)(lower_bound(li + 1 , li + 1 + n , height[cur]) - (li + 1));
    ++lb;
    dp[cur] = rangeMax(1 , 1 , n , 1 , lb) + beauty[cur];
    update(1 , 1 , n , lb , dp[cur]);
  }
}

int main() {
  inputAndInit();
  computeDP();
  printf("%lld\n" , *max_element(dp , dp + N));
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
