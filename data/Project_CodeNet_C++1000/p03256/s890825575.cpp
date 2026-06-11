#include<bits/stdc++.h>
#define maxn 400010
using namespace std;
char s[maxn];
int out[maxn][2], used[maxn], dl[maxn], head[maxn], nxt[maxn * 2], a[maxn * 2], edge;
void create(int u, int v)
{
	edge++; a[edge] = v; nxt[edge] = head[u]; head[u] = edge;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		create(u, v); create(v, u);
		if (s[v] == 'A') out[u][0]++; else out[u][1]++;
		if (s[u] == 'A') out[v][0]++; else out[v][1]++;
	}
	int lef = 1, righ = 0;
	for (int i = 1; i <= n; i++)
		if (out[i][0] == 0 || out[i][1] == 0) {used[i] = 1; dl[++righ] = i;}
	while (lef <= righ)
	{
		int u = dl[lef];
		for (int i = head[u]; i; i = nxt[i])
		{
			int v = a[i];
			if (s[u] == 'A') out[v][0]--; else out[v][1]--;
			if (used[v] == 0 && (out[v][0] == 0 || out[v][1] == 0))
			{
				used[v] = 1;
				dl[++righ] = v;
			}
		}
		lef++;
	}
	for (int i = 1; i <= n; i++)
		if (used[i] == 0) {puts("Yes"); return 0;}
	puts("No");
	return 0;
}