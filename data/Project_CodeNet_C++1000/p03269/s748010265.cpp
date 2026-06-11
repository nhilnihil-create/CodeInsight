#include <bits/stdc++.h>
using namespace std;
#define mp(a, b) make_pair(a, b)
typedef pair<int, int> pii;
const int maxn = 22;
int L, n, m, cur;
int bin[maxn];
vector<pii> E[maxn], G[maxn];
int main()
{
	scanf("%d", &L);
	bin[0] = 1;
	for(int i = 1; i < maxn; ++i)
		bin[i] = bin[i - 1] * 2;
	--L;
	for(n = 2; bin[n - 1] <= L; ++n);
	for(int i = n - 1; i >= 2; --i)
	{
		E[i].push_back(mp(i + 1, 0));
		E[i].push_back(mp(i + 1, bin[n - 1 - i]));
	}
	E[1].push_back(mp(2, 0));
	L -= bin[n - 2];
	cur += bin[n - 2]; 
	for(int i = 2; i <= n; ++i)
		if(L >= bin[n - i] - 1)
		{
			E[1].push_back(mp(i, cur));
			L -= bin[n - i];
			cur += bin[n - i];
		}
	if(n <= 20)
	{
		for(int i = 1; i <= n; ++i)
			m += E[i].size();
		printf("%d %d\n", n, m);
		for(int i = 1; i <= n; ++i)
			for(auto v : E[i])
				printf("%d %d %d\n", i, v.first, v.second);
	}
	else
	{
		for(int i = 2; i <= n; ++i)
			for(auto v : E[i])
				G[i - 1].push_back(mp(v.first - 1, v.second));
		for(auto v : E[1])
			if(v.first == 2)
				for(auto k : E[2])
					G[1].push_back(mp(2, v.second + k.second));
			else
				G[1].push_back(mp(v.first - 1, v.second));
		--n;
		sort(G[1].begin(), G[1].end());
		G[1].erase(unique(G[1].begin(), G[1].end()), G[1].end());
		for(int i = 1; i <= n; ++i)
			m += G[i].size();
		printf("%d %d\n", n, m);
		for(int i = 1; i <= n; ++i)
			for(auto v : G[i])
				printf("%d %d %d\n", i, v.first, v.second);
	}
	return 0;
}