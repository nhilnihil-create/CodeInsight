#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

typedef long long int64;

const int maxn = 100005;
int n, size[maxn];
int64 d[maxn];
std::map<int64, int> s;

int main()
{
	static int id[maxn];
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%lld", d + i), s[d[i]] = i, id[i] = i;
	std::sort(id + 1, id + 1 + n, [](int x, int y) { return d[x] < d[y]; });
	std::vector<std::pair<int, int>> e;
	for (int i = 1; i <= n; ++i)
		size[i] = 1;
	for (int i = n; i != 1; --i)
	{
		if (2 * size[id[i]] >= n || !s.count(d[id[i]] - (n - 2 * size[id[i]])))
		{
			puts("-1");
			return 0;
		}
		int fa = s[d[id[i]] - (n - 2 * size[id[i]])];
		e.emplace_back(fa, id[i]);
		size[fa] += size[id[i]];
		d[id[1]] -= size[id[i]];
	}
	if (d[id[1]])
		puts("-1");
	else
		for (const auto &p : e)
			printf("%d %d\n", p.first, p.second);
	return 0;
}
