#include <algorithm>
#include <cstdio>
#include <map>
using ll = long long;
ll arr[100005], sum[100005];
int idx[100005], fa[100005], sz[100005];
std::map<ll, int> app;
int main()
{
	// freopen("ARC103-F.in", "r", stdin);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%lld", arr + i);
		app[arr[i]] = i;
		idx[i] = i;
		sz[i] = 1;
	}
	std::sort(idx, idx + n, [&] (int x, int y) { return arr[x] > arr[y]; });
	for (int i = 0; i + 1 < n; i++)
	{
		int u = idx[i];
		ll x = n - sz[u] * 2;
		if (x <= 0 || !app.count(arr[u] - x))
		{
			puts("-1");
			return 0;
		}
		fa[u] = app[arr[u] - x];
		sz[fa[u]] += sz[u];
		sum[fa[u]] += sum[u] + sz[u];
	}
	if (sum[idx[n - 1]] != arr[idx[n - 1]])
	{
		puts("-1");
		return 0;
	}
	for (int i = 0; i + 1 < n; i++)
		printf("%d %d\n", idx[i] + 1, fa[idx[i]] + 1);
	return 0;
}
