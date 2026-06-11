#include "bits/stdc++.h"
#define in std::cin
#define out std::cout
#define rep(i,N) for(LL i=0;i<N;++i)
typedef long long int LL;

std::vector<std::vector<LL>>G;
std::vector<LL>dist;

void dfs(LL v, LL d, LL p)
{
	dist[v] = d;
	for (LL u : G[v])
	{
		if (u != p) dfs(u, d + 1, v);
	}
}

int main()
{
	LL N;
	in >> N;
	std::vector<LL>a(N), b(N);
	rep(i, N) in >> a[i] >> b[i];

	G.resize(N + 1); dist.resize(N + 1);
	LL maxD_num = 0, maxD_index, diameter = 0;
	rep(i, N)
	{
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	dfs(1, 0, -1);
	for (LL i = 1; i <= N; ++i)
	{
		if (maxD_num < dist[i])
		{
			maxD_num = dist[i];
			maxD_index = i;
		}
	}
	dfs(maxD_index, 0, -1);
	for (LL i = 1; i <= N; ++i) diameter = std::max(diameter, dist[i]);

	out << (diameter % 3 == 1 ? "Second" : "First") << std::endl;
}
