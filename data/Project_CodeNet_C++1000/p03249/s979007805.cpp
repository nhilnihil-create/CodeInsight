#include <map>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define N 100005
#define M 200005
map<ll, int>p;
map<ll, int>::iterator it;
int fat[N], siz[N], a[N], b[N], fir[N], nex[M], tar[M];
int n, cnt;
void Add(int a, int b)
{
	++cnt;
	tar[cnt] = b;
	nex[cnt] = fir[a];
	fir[a] = cnt;
}
ll wd[N], d[N];
void Dfs(int x, int dis)
{
    siz[x] = 1;
    d[1] += dis;
	for (int i = fir[x]; i; i = nex[i])
    {
		if (tar[i] != fat[x])
		{
			fat[tar[i]] = x;
			Dfs(tar[i], dis + 1);
			siz[x] += siz[tar[i]];
        }
    }
}
void Dfs(int x)
{
	for (int i = fir[x]; i; i = nex[i])
	{
		if (tar[i] != fat[x])
        {
            d[tar[i]] = d[x] + n - siz[tar[i]] * 2;
            Dfs(tar[i]);
        }
    }
}
int Getbel(int x)
{
	if (fat[x] == x)
		return x;
	return fat[x] = Getbel(fat[x]);
}
int main()
{
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &wd[i]);
		p[wd[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		fat[i] = i;
		siz[i] = 1;
	}
	it = p.end();
	for (it--; it != p.begin(); it--)
	{
		if (n - siz[it -> second] * 2 == 0 || !p.count(it -> first - (n - siz[it -> second] * 2)))
		{
			puts("-1");
			return 0;
		}
		cnt++;
		a[cnt] = it -> second;
		b[cnt] = p[it -> first - (n - siz[it -> second] * 2)];
		siz[fat[a[cnt]] = Getbel(b[cnt])] += siz[a[cnt]];
	}
	cnt = 0;
	for (int i = 1; i < n; i++)
	{
		Add(a[i], b[i]);
		Add(b[i], a[i]);
	}
	fat[1] = 0;
	Dfs(1, 0);
	Dfs(1);
	for (int i = 1; i <= n; i++)
	{
		if (wd[i] != d[i])
		{
			puts("-1");
		    return 0;
		}
	}
	for (int i = 1; i < n; i++)
		printf("%d %d\n", a[i], b[i]);
}