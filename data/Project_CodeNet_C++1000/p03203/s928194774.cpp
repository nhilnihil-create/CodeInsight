#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <iomanip>
#include <assert.h>

using namespace std;

const int MAXN = 200005;

int n,m,q;
int MAX[MAXN];

pair<int,int> c[MAXN];

void update(int p,int x)
{
	while (p <= m)
	{
		MAX[p] = max(MAX[p],x);
		p += (p & -p);
	}
}

int query(int p)
{
	int res = -(1 << 30);
	while (p >= 1)
	{
		res = max(res,MAX[p]);
		p -= (p & -p);
	}
	return res;
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 1;i <= q;i++)
		scanf("%d%d",&c[i].first,&c[i].second);
	sort(c + 1,c + q + 1);
	for (int i = 1;i <= m;i++)
		MAX[i] = -(1 << 30);
	for (int i = 1;i <= q;i++)
	{
		if (c[i].first < c[i].second)
			continue;
		if (c[i].first == c[i].second)
		{
			update(c[i].second,0);
			continue;
		}
		if (c[i].first - c[i].second > query(c[i].second) + 1)
		{
			cout << c[i].first - 1 << endl;
			return 0;
		}
		else
			update(c[i].second,c[i].first - c[i].second);
	}
	cout << n << endl;
	return 0;
}