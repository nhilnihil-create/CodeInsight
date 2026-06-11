#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
/*                   وتزودوا فإن خير الزاد التقوى                    */
/*       وما تدري نفس ماذا تکسب غدا وما تدري نفس باي ارض تموت      */
#include<unordered_map>
using namespace std;
#define endl '\n'
#define ll long long
#define PI acos(-1)
#define watch(x) cerr<<#x<<" = { "<<x<<" }\n"
#define sz(n) n.size()
#define Mo7med_Sayed fast();
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define RT(v) return cout<<v,0;
#define mem(dp,n) memset(dp,n,sizeof dp)
const double EPS = (1e-7);
const ll OO = INT_MAX, mod = 1e9 + 7, N = 2e5 + 5;
void run() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
#endif
}
ll gcd(ll a, ll b) { return !b ? abs(a) : gcd(b, a % b); }
ll lcm(ll a, ll b) { return abs(a / gcd(a, b)) * b; }
void fast()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

ll  n, m, w, k, t;
ll dp[100005][3];
vector<vector<ll>>adj;
ll solve(int u, int p, bool co)
{
	ll& ret = dp[u][co];
	if (~ret)return ret;
	ret = 1;
	for (auto v : adj[u])
	{
		if (v == p)continue;
		ret *= ((co ? solve(v, u, !co) : 0) + (solve(v, u, 1))) % mod;
		ret %= mod;
	}
	return ret %= mod;

}
int main()
{
	run();
	Mo7med_Sayed;
	cin >> n;
	mem(dp, -1);
	adj.resize(n + 1);
	for (int i = 1; i < n; i++) {
		ll u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	RT((solve(1, -1, 0) + solve(1, -1, 1))%mod);
}
