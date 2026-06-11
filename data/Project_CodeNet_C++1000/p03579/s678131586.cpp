#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define getchar getchar_unlocked
#define pb push_back
using namespace std;
constexpr int MAXN = 1e5 + 10;
vector <int> G[MAXN];
bool visit[MAXN];
bool color[MAXN];
bool ck;
int n, m;
inline void dfs(int s)
{
	for(auto u : G[s])
	{
		if(visit[u] == false)
		{
			color[u] = color[s] ^ 1;
			visit[u] = true;
			dfs(u);
		}
		else
		{
			if(color[u] != 1 - color[s])
				ck = true;
		}
	}
}
template <class T>
inline void _read(T &x)
{
	x = 0;
	char t = getchar();
	while(!isdigit(t) && t != '-') t = getchar();
	if(t == '-')
	{
		_read(x);
		x *= -1;
		return ;
	}
	while(isdigit(t))
	{
		x = x * 10 + t - '0';
		t = getchar();
	}
}
int main()
{
	_read(n), _read(m); 
	for(int i = 1, a, b; i <= m; ++i)
	{
		_read(a), _read(b);
		G[a].pb(b);
		G[b].pb(a);
	}

	dfs(1);
	if(ck)
		printf("%lld", 1ll * n * (n - 1) / 2 - m);
	else
	{
		int cnt = 0;
		for(int i = 1; i <= n; ++i)
			cnt += color[i];
		printf("%lld", 1ll * cnt * n - 1ll * cnt * cnt - 1ll * m);
	}
}