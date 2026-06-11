#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
using namespace std;

namespace zyt
{
	typedef long long ll;
	const int N = 1e5 + 10;
	int n, id[N], fa[N], size[N], dis[N];
	ll d[N];
	map<ll, int> mp;
	vector<int> g[N];
	bool cmp(const int a, const int b)
	{
		return d[a] < d[b];
	}
	void dfs(const int u, const int d)
	{
		dis[u] = d;
		for (auto v : g[u])
			dfs(v, d + 1);
	}
	int work()
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%lld", d + i), id[i] = i, mp[d[i]] = i, size[i] = 1;
		sort(id + 1, id + n + 1, cmp);
		for (int i = n; i > 1; i--)
		{
			ll t = d[id[i]] - n + 2LL * size[id[i]];
			mp.erase(d[id[i]]);
			if (mp.count(t))
			{
				size[mp[t]] += size[id[i]], fa[id[i]] = mp[t];
				g[mp[t]].push_back(id[i]);
			}
			else
			{
				puts("-1");
				return 0;
			}
		}
		dfs(id[1], 0);
		ll sum = 0;
		for (int i = 1; i <= n; i++)
			sum += dis[i];
		if (sum != d[id[1]])
			puts("-1");
		else
			for (int i = 1; i <= n; i++)
				if (fa[i])
					printf("%d %d\n", i, fa[i]);
		return 0;
	}
}
int main()
{
	return zyt::work();
}