#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n,m;
int l;
int head[N];
int ina[N], inb[N];
int x,y;
bool vis[N];
struct node
{
	int x,y,next;
}edge[2*N];
char s[N];
queue<int> q;
void add(int x,int y)
{
	l++;
	edge[l].x = x;edge[l].y = y;edge[l].next = head[x];
	head[x] = l;
}
bool top_sort()
{
	for (int i=1;i<=n;i++)
	{
		if (q.empty()) return 0;
		int u = q.front();
		q.pop();
		for (int p = head[u];p;p=edge[p].next)
		{
			if (s[u] == 'A') ina[edge[p].y]--; else inb[edge[p].y]--;
			if (!vis[edge[p].y] && (!ina[edge[p].y] || !inb[edge[p].y]))
			{
				q.push(edge[p].y);
				vis[edge[p].y] = 1;
			}
		}
	}
	return 1;
}
int main()
{
	//idea:由一个无效点推导出其他的无效点，如果最后还有点能构成一个环，那么就有解
	scanf("%d%d", &n, &m);
	scanf("%s", s+1);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d", &x, &y);
		add(x,y);
		add(y,x);
		if (s[x] == 'A') ina[y]++; else inb[y]++;
		if (s[y] == 'A') ina[x]++; else inb[x]++;
	}
	for (int i=1;i<=n;i++)
		if (!ina[i] || !inb[i]) 
		{
			q.push(i);
			vis[i] = 1;
		}
	if (!top_sort()) printf("Yes\n"); else printf("No\n");
}