/*May The Force Be With Me*/
#include <bits/stdc++.h>
#include <stdio.h>
#include <ctype.h>
#pragma GCC optimize ("Ofast")
#define ll long long
#define MOD 1000000007
#define endl "\n"
#define vll vector<long long>
#define mll map<long long,long long>
#define pll pair<long long, long long>
#define all(c) c.begin(),c.end()
#define rall(c) c.rbegin(),c.rend()
#define pb push_back
#define f first
#define s second
#define inf INT_MAX
#define size_1d 10000000
#define size_2d 1000
#define rep(i,v,n) for(ll i = v; i < n; i++)
//Snippets: delta, sieve, fastexp, dfs, bfs, dijkstra, floodfill

using namespace std;

ll n;
double N;
double dp[305][305][305]; // each [] checks for plate type

void Input() {
	cin >> n;
	N = n;
}

double func(ll a, ll b, ll c) {
	if (a + b + c == 0)return 0.0;
	if (dp[a][b][c] > -1.0)return dp[a][b][c];
	double ret = 0.0;
	if (a) ret += (func(a - 1, b, c) + N / (a + b + c)) * a / (a + b + c);
	if (b) ret += (func(a + 1, b - 1, c) + N / (a + b + c)) * b / (a + b + c);
	if (c) ret += (func(a, b + 1, c - 1) + N / (a + b + c)) * c / (a + b + c);
	dp[a][b][c] = ret;
	return ret;
}

void Solve() {
	vll a(n), t(4, 0);
	for (ll i = 0; i < n; i++) cin >> a[i], t[a[i]]++;
	memset(dp, -1, sizeof dp);
	double ans = func(t[1], t[2], t[3]);
	cout.precision(12);
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll T = 1;
	//cin >> T;
	//ll t = 1;
	while (T--) {
		Input();
		//cout << "Case " << t << ": ";
		Solve();
		//t++;
	}
	return 0;
}