#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 400100;
struct edges
{
	int to, next;
}edge[maxn];
int point[maxn] = {0}, te = 0;
int dua[maxn] = {0}, dub[maxn] = {0};
char v[maxn];
void add(int a, int b)
{
	if(v[b] == 'A')
		dua[a] ++;
	else
		dub[a] ++;
	te ++;
	edge[te].to = b;
	edge[te].next = point[a];
	point[a] = te;
}
int n, m;
int cnt;
bool flag[maxn];
queue<int> q;
int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)
		cin >> v[i];
	cnt = n;
	for(int i = 1; i <= m; i ++)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}
	for(int i = 1; i <= n; i ++)
	{
		if(dua[i] == 0 || dub[i] == 0)
			q.push(i);
		flag[i] = 1;
	}
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		if(!flag[now])
			continue;
		cnt --;
		flag[now] = 0;
		for(int e = point[now]; e; e = edge[e].next)
		{
			if(v[now] == 'A')
			{
				dua[edge[e].to] --;
				if(dua[edge[e].to] == 0 && flag[edge[e].to])
					q.push(edge[e].to);
			}
			else
			{
				dub[edge[e].to] --;
				if(dub[edge[e].to] == 0 && flag[edge[e].to])
					q.push(edge[e].to);
			}
		}
	}
	if(cnt == 0)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
	return 0;
}