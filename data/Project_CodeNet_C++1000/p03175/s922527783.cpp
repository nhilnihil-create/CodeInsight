#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100100
#define MOD 1000000007

vector<int>adj[sz];

// c = 1 - white parent
// c = 0 - black parent

pair<ll, ll> dfs(int s, int p)
{
	if (adj[s].size() == 1 && adj[s][0] == p)
		return {1, 1};
	pair<ll, ll>ans = {1, 1};
	for (auto it : adj[s])
	{
		if (it == p)
			continue;
		pair<ll, ll>cur = dfs(it, s);
		ans.first = (ans.first * (cur.first + cur.second) % MOD) % MOD;
		ans.second = (ans.second * cur.first % MOD) % MOD;
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	if (n == 1)
	{
		cout << 2;
		return 0;
	}
	for (int i = 0; i < n - 1; i++)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	pair<ll, ll> ans = dfs(1, -1);
	cout << (ans.first + ans.second) % MOD;
	return 0;
}