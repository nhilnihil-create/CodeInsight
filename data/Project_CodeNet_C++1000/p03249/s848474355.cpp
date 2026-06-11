#include <bits/stdc++.h>

template <class T>
inline void read(T &res)
{
	res = 0; bool bo = 0; char c;
	while (((c = getchar()) < '0' || c > '9') && c != '-');
	if (c == '-') bo = 1; else res = c - 48;
	while ((c = getchar()) >= '0' && c <= '9')
		res = (res << 3) + (res << 1) + (c - 48);
	if (bo) res = ~res + 1;
}

typedef long long ll;

const int N = 1e5 + 5;

int n, p[N], fa[N], sze[N], dis[N];
ll d[N], dsum;
std::map<ll, int> occ;

inline bool comp(int a, int b) {return d[a] < d[b];}

int main()
{
	read(n);
	for (int i = 1; i <= n; i++) read(d[i]), p[i] = i, sze[i] = 1;
	std::sort(p + 1, p + n + 1, comp);
	for (int i = 1; i <= n; i++) occ[d[i]] = i;
	for (int i = n; i >= 2; i--)
	{
		int u = p[i]; occ[d[u]] = 0;
		int v = occ[d[u] - n + (sze[u] << 1)];
		if (!v) return puts("-1"), 0;
		fa[u] = v; sze[v] += sze[u];
	}
	for (int i = 2; i <= n; i++) dis[p[i]] = dis[fa[p[i]]] + 1;
	for (int i = 1; i <= n; i++) dsum += dis[i];
	if (d[p[1]] != dsum) return puts("-1"), 0;
	for (int i = 2; i <= n; i++) printf("%d %d\n", fa[p[i]], p[i]);
	return 0;
}