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
const ll N = 1e5 + 10;
const ll INF = 1e9;
const ll M = 1e9 + 7;
ll n;
ll d[N], dp[N][2];
vector <ll> adj[N];

void makeRooted() {
  fill (d , d + N , INF);
  queue <ii> q;
  q.push({1 , 0});
  while (q.size()) {
    ii cur = q.front(); q.pop();
    ll u = cur.fi, cd = cur.se;
    if (d[u] != INF) continue;
    d[u] = cd;
    for (ll v : adj[u]) {
      q.push({v , cd + 1});
    }
  }
  return;
}

ll add(ll a , ll b) {
  return ((a % M) + (b % M)) % M;
}

ll mul(ll a , ll b) {
  return ((a % M) * (b % M)) % M;
}

ll f(ll u , bool col) {
  ll &sol = dp[u][col];
  if (sol != -1) return sol;
  sol = 1;
  for (ll v : adj[u]) {
    if (d[v] < d[u]) continue;
    ll cur = 0;
    if (col) {
      cur = add(cur , f(v , !col));
    } else {
      cur = add(cur , add(f(v , !col) , f(v , col)));
    }
    sol = mul(sol , cur);
  }
  return sol;
}

int main() {
  in(n);
  for (ll i = 1, u, v ; i < n ; i++) {
    in(u); in(v);
    adj[u].pb(v);
    adj[v].pb(u);
  }
  makeRooted();
  memset (dp , -1 , sizeof dp);
  printf("%lld\n" , add(f(1 , 0) , f(1 , 1)));
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
