/////////////////////////////////TEST CASES////////////////////////////////////
/*
*/
/////////////////////////////////////CODE//////////////////////////////////////		
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define FORD(i, a, b) for (ll i = a ; i > b ; i--)
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define PI 3.14159265
typedef long long ll;
#define vl vector<ll> 
#define IN(inp) ll inp;cin>>inp;
#define pb push_back
#define all(a) a.begin(),a.end()
#define FR(i,a) for(auto i:a)
#define what(A) cout<<#A<<" is "<<A<<endl;
ll MAX = 100000000000;
ll MOD = 1000000007;
map<ll, vl>g;
ll vis[100010], dp[100010];
ll dfs(ll node)
{
	if (vis[node])
		return dp[node];
	vis[node] = 1;
	FOR(i, 0, g[node].size())
	{
		dp[node] = max(dp[node],1+dfs(g[node][i]));
	}
	return dp[node];
}
void solve()
{
	IN(n)IN(m);
	FOR(i, 0, m)
	{
		IN(in1)IN(in2);
		g[in1].pb(in2);
	}
	ll ans = 0;
	FOR(i, 1, n + 1)
	{
		//what(dfs(i))
		ans = max(ans, dfs(i));
	}
	cout << ans;
}
int main()
{
	fastio
		//freopen("input.txt", "rt", stdin);
		//freopen("output.txt", "wt", stdout);
		ll test = 1;
	//cin >> test;
	while (test--)
	{
		solve();
	}
}