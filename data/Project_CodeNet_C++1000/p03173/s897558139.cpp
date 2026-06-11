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
#define inf 1e18l
#define size_1d 10000000
#define size_2d 1000
#define rep(i,v,n) for(ll i = v; i < n; i++)
//Snippets: delta, sieve, fastexp, dfs, bfs, dijkstra, floodfill

using namespace std;

ll n;

void Input() {
	cin >> n;
}

void Solve() {
	vll a(n), b(n, 0);
	for (ll i = 0; i < n; i++) cin >> a[i];
	b[0] = a[0];
	for (ll i = 1; i < n; i++) b[i] = a[i] + b[i - 1];
	ll dp[n][n]; // min cost of combining interval i,j into one cell
	for (ll i = 0; i < n; i++)for (ll j = 0 ; j < n; j++)dp[i][j] = inf;
	for (ll i = n - 1; i >= 0; i--)for (ll j = i; j < n; j++) {
			if (i == j)dp[i][j] = 0;
			else {
				for (ll k = i; k < j; k++)
					dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + b[j] - ((!i) ? 0 : b[i - 1]));
			}
		}
	cout << dp[0][n - 1];
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