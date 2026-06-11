#include <cstdio>
#include <cstring>
 
int c[201000]; char s[201000];
int st[201000], top = 0, inq[201000][2], T[201000];
int h[201000], nxt[401000], to[401000], K = 0;
bool used[201000][2];
int flag = 0;

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void dfs(int x, int t)
{
	if(inq[x][t]) {flag = 1; return;}
	if(used[x][t]) return;
	st[++top] = x; T[top] = t; 
	inq[st[top]][T[top]] = 1;
	used[x][t] = 1;
	for(int i = h[x]; i; i = nxt[i])
	{
		if(flag) return;
		if(c[to[i]] == (t ^ 1))
		{
			dfs(to[i], c[x]);
		}
	}
	inq[st[top]][T[top]] = 0;
	top--;
}
 
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) c[i] = (s[i] == 'A' ? 1 : 0);
	for(int i = 1; i <= m; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		ins(u, v); ins(v, u);
	}
	for(int i = 1; i <= n; i++)
	{
		if(!used[i][0])
		{
			dfs(i, 0);
			if(flag) return 0 * puts("Yes");
		}
		if(!used[i][1])
		{
			dfs(i, 1);
			if(flag) return 0 * puts("Yes");
		}
	}
	puts("No");
	return 0;
}