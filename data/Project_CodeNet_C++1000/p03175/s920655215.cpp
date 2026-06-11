#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef long long ll;

vector<ll> adj[100001];

ll dp[100005][2];

ll solve(ll node, bool constrall, ll pr)
{
	ll ans = 0;

	if (dp[node][constrall] != -1)
		return dp[node][constrall];

	ll w1 = 1;
	//If I pall node white, no constralls on children
	for (ll child : adj[node])
	{
		if (child != pr)
			w1 = (w1 * solve(child, 0, node)) % mod;
	}
	ans = (ans + w1) % mod;

	//If I can pall it black, children have constrall, can't be black
	if (!constrall) {
		ll w2 = 1;
		for (ll child : adj[node])
		{
			if (child != pr)
				w2 = (w2 * solve(child, 1, node)) % mod;
		}
		ans = (ans + w2) % mod;
	}

	return dp[node][constrall] = ans;
}

int main()
{

	memset(dp, -1, sizeof(dp));

	ll n;
	cin >> n;

	ll e = n - 1;
	while (e--)
	{
		ll a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	cout << solve(1, 0, -1); //root, constrall, parent
}