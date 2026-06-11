#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

ll n, m, ans = 0;
vv(ll) G(51, vector<ll>(51, 0));
vector<bool> seen(51);

void	dfs(int now)
{
	seen[now] = 1;
	for (int i = 1; i <= n; ++i)
	{
		if (G[i][now] && seen[i] == 0)
			dfs(i);
	}
}

int		main(void)
{
	cin >> n >> m;

	vector<pair<ll, ll>> P;
	for (ll i = 0; i < m; ++i)
	{
		ll a, b;
		cin >> a >> b;
		P.push_back({a, b});
		G[a][b] = true;
		G[b][a] = true;
	}
	for (int i = 0; i < m; ++i)
	{
		ll p1 = P[i].first;
		ll p2 = P[i].second;
		G[p1][p2] = false;
		G[p2][p1] = false;
		seen.assign(51, false);
		dfs(1);
		int j;
		for (j = 1; seen[j] && j <= n; ++j)
			;
		if (j == n+1)
			++ans;
		G[p1][p2] = true;
		G[p2][p1] = true;
	}
	cout << m - ans << endl;
}

