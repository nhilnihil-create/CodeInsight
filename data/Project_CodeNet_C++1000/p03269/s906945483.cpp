#include <bits/stdc++.h>
using namespace std;
#define mp(a, b) make_pair(a, b)
typedef pair<int, int> pii;
const int maxn = 25;
vector<pii> E[maxn];
void dfs(int L, int s, int & t)
{
	if(L == 2)
	{
		E[t - 1].push_back(mp(t, 0));
		E[t - 1].push_back(mp(t, 1));
		return;
	}
	if(L & 1)
	{
		dfs(L - 1, s, t);
		E[s].push_back(mp(t, L - 1));
	}
	else
	{
		dfs(L / 2, s + 1, ++t);
		for(int i = s + 1; i < t; ++i)
			for(auto & e : E[i])
				e.second *= 2;
		E[s].push_back(mp(s + 1, 0));
		E[s].push_back(mp(s + 1, 1));
	}
}
int main()
{
	int L, t;
	scanf("%d", &L);
	dfs(L, 1, t = 2);
	int m = 0;
	for(int i = 1; i <= t; ++i)
		m += E[i].size();
	printf("%d %d\n", t, m);
	for(int i = 1; i <= t; ++i)
		for(auto e : E[i])
			printf("%d %d %d\n", i, e.first, e.second);
	return 0;
}