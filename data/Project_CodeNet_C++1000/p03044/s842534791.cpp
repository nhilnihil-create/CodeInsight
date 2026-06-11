#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = N * 2;

int n;
int h[N], e[M], w[M], ne[M], idx;
int dist[N], q[M];

void add(int a, int b, int c)
{
	e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u, int fa, int d)
{
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (j == fa) continue;
		
		dist[j] = dist[u] + w[i];
		dfs(j, u, dist[j]);
	}
}

int main()
{
	memset(h, -1, sizeof h);
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i ++ )
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c), add(b, a, c);
	}
	
	dfs(1, -1, 0);
	
	// memset(dist, -1, sizeof dist);
	// int hh = 0, tt = -1;
	// dist[1] = 0;
	// q[ ++ tt] = 1;
// 	
	// while (hh <= tt)
	// {
		// int t = q[hh ++ ];
// 		
		// for (int i = h[t]; ~i; i = ne[i])
		// {
			// int j = e[i];
			// if (dist[j] >= 0) continue;
// 			
			// q[ ++ tt] = j;
			// dist[j] = dist[t] + w[i];
		// }
	// }
	
	for (int i = 1; i <= n; i ++ ) printf("%d\n", dist[i] & 1);
    return 0;
}