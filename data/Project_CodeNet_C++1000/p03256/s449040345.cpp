#include <bits/stdc++.h>
// #include "lib.h"
using namespace std;
#define FAST ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define LLINF 1234567890987654321
#define INF 1234567890
#define pb push_back
#define ins insert
#define f first
#define s second
#define db 0
#define MAXN 200006
#define MAXK 200006
#define MAXX 200006
#define rep(kk, l1, l2)for(ll kk = l1; kk < l2; kk++)
#define bg(ms) *ms.begin()
#define ed(ms) *prev(ms.end(), 1)
#define addedge(a, b, c) v[a].pb(pi(b, c)); v[b].pb(pi(a, c))
#define ph push
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef pair <ll, ll> pi;
typedef pair <ll, pi> spi;
typedef pair <pi, pi> dpi;
ll n, m, AB[MAXN], voided[MAXN], vis[MAXN], ans;
string ss;
queue <ll> q;
vector <ll> v[MAXN];
int main()
{
	FAST   //my macro check above(the ios_base speed one)
	cin >> n >> m >> ss;
	for(ll i = 1; i <= n; i++)AB[i] = ((ss[i-1]=='A')?0:1);
	for(ll i = 0; i < m; i++)
	{
		ll n1, n2;
		cin >> n1 >> n2;
		v[n1].pb(n2);
		v[n2].pb(n1);
	}
	for(ll i = 1; i <= n; i++)v[i].resize( unique(v[i].begin(), v[i].end()) - v[i].begin());
	for(ll i = 1; i <= n; i++)q.push(i);
	while(!q.empty())
	{
		ll node = q.front();
		q.pop();
		if(vis[node] || voided[node])continue;
		ll a = 0, b = 0;
		vis[node] = 1;
		for(auto i : v[node])
		{
			if(voided[i])continue;
			if(AB[i] == 0)a++;
			else b++;
		}
		if(a >= 1 && b >= 1)   //don't need to void is a valid node
		{
			continue;
		}
		voided[node] = 1;
		ans++;
		for(auto i : v[node]) //push in neighbours as u are no longer a valid node
		{
			if(voided[i] || !vis[i])continue;
			vis[i] = 0;
			q.push(i);
		}
	}
	cout << ((n-ans > 0) ? "Yes" : "No") << "\n";
}
