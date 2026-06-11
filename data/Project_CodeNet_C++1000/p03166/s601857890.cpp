#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sz 100100

vector<int>adj[sz];
int indeg[sz];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;
	while (m--)
	{
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		indeg[b]++;
	}
	queue<pair<int, int>>q;
	for (int i = 1; i <= n; i++)
	{
		if (indeg[i] == 0)
			q.push({i, 0});
	}
	int ans = 0;
	while (!q.empty())
	{
		auto x = q.front();
		ans = x.second;
		q.pop();
		for (auto it : adj[x.first])
		{
			indeg[it]--;
			if (indeg[it] == 0)
				q.push({it, x.second + 1});
		}
	}
	cout << ans;

	return 0;
}