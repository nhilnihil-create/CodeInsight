#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr(i,k) for(i=0;i<k;i++)
#define deb(x) cerr<<#x<<"  = "<<x<<endl;
#define deb2(x,y) cerr<<#x<<" ="<<x<<endl<<#y<<" ="<<y<<endl;
#define SZ(x) (x).size();
#define ll long long
#define mod 1000000007
#define ff first
#define ss second
#define pb push_back
#define em emplace_back
#define ulli unsigned long long int
#define inf 1e18
#define endl "\n"
typedef vector<vector<ll>> vvll;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;
void solve();

int main() {
	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ll t;
	t = 1;

	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

ll calc(vll adj[], ll s, ll f, ll par, vvll &dp)
{

	if (dp[s][f] != -1)
		return dp[s][f];

	ll ans = 0;
	ll w1 = 1;

	for (auto k : adj[s])
	{
		if (k != par)
		{
			w1 = (w1 * calc(adj, k, 0, s, dp)) % mod;
		}
	}
	ans += w1;

	if (f == 0)
	{
		ll w2 = 1;
		for (auto k : adj[s])
		{
			if (k != par)
			{
				w2 = (w2 * calc(adj, k, 1, s, dp)) % mod;
			}
		}
		ans = (ans + w2) % mod;
	}

	return dp[s][f] = ans;
}

inline void solve()
{
	ll n, i, u, v, ans;
	cin >> n;

	vector<ll> adj[n + 1];

	for (i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	vvll dp(n + 1, vll(3, -1));

	ans = calc(adj, 1, 0, -1, dp);

	cout << ans << endl;
}
