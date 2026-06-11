#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
vector<int> E[maxn];
#define mp(a, b) make_pair(a, b)
typedef pair<int, int> pii;
int ans;
void check(pii & x, int y)
{
	if(y > x.first) 
	{
		x.second = x.first;
		x.first = y;
	}
	else if (y > x.second) x.second = y;
}
int dfs(int x, int fa)
{
	pii Max = mp(-1, -1);
	for(auto v : E[x])
		if(v != fa)
			check(Max, dfs(v, x));
	++Max.first;
	++Max.second;
	ans = max(ans, Max.first + Max.second);
	return Max.first;
}
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	dfs(1, 0);
	++ans;
	if((ans - 2) % 3)
		puts("First");
	else
		puts("Second");
	return 0;
}