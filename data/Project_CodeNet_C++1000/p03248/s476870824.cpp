#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 10;
int cnt, n;
char s[maxn];
vector<int>g[maxn];
bool check()
{
	//n = strlen(s + 1);
	//cout << "!" << endl;
	if(s[1] != '1' || s[n] != '0')
		return 0;
	//cout << "!" << endl;
	int st = 1, ed = n - 1;
	while(st < ed)
	{
		if(s[st] != s[ed])
			return 0;
		st ++; ed --;
	}
	return 1;
}
struct Edge
{
	int u, v;
}e[maxn * 2];
int edge_num;
void dfs(int x, int fa)
{
	for(int i = g[x].size() - 1; i >= 0; i --)
	{
		int to = g[x][i];
		if(to == fa)
			continue;
		e[++ edge_num].u = x;
		e[edge_num].v = to;
		dfs(to, x);
	}
}
int main()
{
	//int n;
	//scanf("%d", &n);
	scanf("%s", s + 1);
	n = strlen(s + 1);
	if(!check())
	{
		cout << -1;
		return 0;
	}
	int op = ++ cnt;
	g[1].push_back(2); g[2].push_back(1);
	op = ++ cnt;
	for(int i = 2; i < n; i ++)
	{
		if(s[i] == '1')
		{
			if(s[i - 1] != '0')
			{
				++ cnt;
				g[cnt].push_back(op);
				g[op].push_back(cnt);
			}
			op = cnt;
		}
		else
		{
			if(s[i - 1] == '1')
			{
				++ cnt;
				g[cnt].push_back(op);
				g[op].push_back(cnt);
				++ cnt;
				g[cnt].push_back(op);
				g[op].push_back(cnt);
			}
			else
			{
				++ cnt;
				g[cnt].push_back(op);
				g[op].push_back(cnt);
			}
		}
	}
	dfs(1, 0);
	for(int i = 1; i < n; i ++)
		printf("%d %d\n", e[i].u, e[i].v);
	return 0;
}
