#include "bits/stdc++.h"

using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef long double ld;
const ll mod = 1e9 + 7;

ll solve(void)
{
	ll n, m;
	cin >> n >> m;

	vector<vll> e(n, vll());

	for (ll i = 0; i < m; i++)
	{
		ll x, y, z;
		cin >> x >> y >> z;
		x--; y--;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	ll ans = 0;
	vector<bool> visited(n, false);
	for (ll i = 0; i < n; i++)
	{
		if (visited[i]) { continue; }
		ans ++;
		visited[i] = true;

		queue<ll> q;
		q.push(i);

		while (!q.empty())
		{
			ll f = q.front();
			q.pop();
			visited[f] = true;
			for (auto i : e[f])
			{
				if (visited[i]) { continue; }
				q.push(i);
			}
		}
	}
	
	cout << ans << endl;


	return 0;
}

int main(void)
{
	while(solve()){}

	return 0;
}