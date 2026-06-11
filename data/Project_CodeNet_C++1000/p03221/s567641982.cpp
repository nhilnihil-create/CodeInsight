#include<bits/stdc++.h>
using namespace std;

struct data2
{
	int p, y, nn, num;
}c[100010];

bool cmp(data2 u, data2 v)
{
	if (u.p == v.p) return u.y<v.y;
	return u.p < v.p; 
}
bool cmp2(data2 u, data2 v)
{
	return u.nn < v.nn; 
}

int ans[100010];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d", &c[i].p, &c[i].y), c[i].nn = i;
	sort(c+1, c+m+1, cmp);
	for (int i=1, j=1; i <= m; i=j)
	{
		int k = 0;
		while (j <= m && c[j].p == c[i].p) 
		{
			++k;
			c[j].num = k;
			++j; 
		}
	}
	sort(c+1, c+m+1, cmp2);
	for (int i = 1; i <= m; ++i)
		printf("%06d%06d\n", c[i].p, c[i].num);
	return 0;
} 