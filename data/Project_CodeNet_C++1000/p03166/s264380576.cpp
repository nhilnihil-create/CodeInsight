#include<bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define fr(i,k) for(i=0;i<k;i++)
#define ALL(c) (c).begin(),(c).end()
#define deb(x) cerr<<#x<<"  = "<<x<<endl;
#define SZ(x) (x).size();
#define ll long long
#define MOD 1000000007
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define em emplace_back
#define ulli unsigned long long int
#define INF 1e18
#define endl "\n"
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
void solve();

void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}


int main() {
	fastio;
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int t;
	t = 1;

	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}

ll calc(vi adj[], ll s, vector<ll> &dp)
{
	if (dp[s] != -1)
		return dp[s];

	bool leaf = 1;
	for (auto k : adj[s])
	{
		leaf = 0;
		dp[s] = max(dp[s], 1 + calc(adj, k, dp));
	}

	if (leaf == 1)
		dp[s] = 0;

	return dp[s];
}

void solve()
{
	ll n, m, i, u, v, ans = INT_MIN;
	cin >> n >> m;

	vi adj[n + 1];

	for (i = 0; i < m; i++)
	{
		cin >> u >> v;
		adj[u].pb(v);
	}

	vector<ll> dp(n + 1, -1);

	for (i = 1; i <= n; i++)
		ans = max(ans, calc(adj, i, dp));

	cout << ans << endl;

}
