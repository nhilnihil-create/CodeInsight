#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 200100;
struct edges
{
	int to, next;
}edge[maxn * 2];
int point[maxn] = {0}, te = 0;
void add(int a, int b)
{
	te ++;
	edge[te].to = b;
	edge[te].next = point[a];
	point[a] = te;
}
int n;
int len = 0, far;
void dfs(int now, int p, int dis)
{
	dis ++;
	if(dis > len)
	{
		far = now;
		len = dis;
	}
	for(int e = point[now]; e; e = edge[e].next)
		if(edge[e].to != p)
			dfs(edge[e].to, now, dis);
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n;
	for(int i = 1; i < n; i ++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	dfs(1, 0, 0);
	dfs(far, 0, 0);
	if(len % 3 == 2)
		cout << "Second" << endl;
	else
		cout << "First" << endl;
	return 0;
}