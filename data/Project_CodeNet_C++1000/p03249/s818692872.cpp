#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, sz[100007], fa[100007];
pair<int, int>p[100007];
vector<int>e[100007];
int read()
{
	int num = 0;
	char c = getchar();
	while (c<'0' || c>'9')c = getchar();
	while (c >= '0' && c <= '9')num = num * 10 + c - '0', c = getchar();
	return num;
}
int dfs(int w, int f)
{
	int res = 0;
	for (int i = 0, lim = e[w].size(); i < lim; i++)
		res += dfs(e[w][i], w) + sz[e[w][i]];
	return res;
}
signed main()
{
	n = read();
	for (int i = 1; i <= n; i++)
		p[i] = make_pair(read(), i);
	sort(p + 1, p + n + 1);
	for (int i = n; i > 1; i--)
	{
		int x = p[i].second;
		sz[x]++;
		int pos = lower_bound(p + 1, p + n + 1, make_pair(p[i].first + 2 * sz[x] - n, 0LL)) - p;
		if (pos >= i || p[i].first + 2 * sz[x] - n != p[pos].first) { cout << -1 << endl; return 0; }
		fa[x] = p[pos].second;
		sz[fa[x]] += sz[x];
		e[fa[x]].push_back(x);
	}
	sz[p[1].second]++;
	if(dfs(p[1].second,0)!=p[1].first) { cout << -1 << endl; return 0; }
	for (int i = 1; i <= n; i++)
		if (fa[i])printf("%lld %lld\n", fa[i], i);
	return 0;
}