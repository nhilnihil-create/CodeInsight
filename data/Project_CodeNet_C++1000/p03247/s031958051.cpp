#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 1005;

int n,m;
int x[MAXN];
int y[MAXN];
int d[40];

string ans[MAXN];

bool ok(int l,int x,int y)
{
	return (long long)abs(x) + abs(y) <= (1ll << (l + 1)) - 1;
}

int main()
{
	scanf("%d",&n);
	bool odd = 0,even = 0;
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		odd |= (x[i] + y[i]) & 1;
		even |= ~(x[i] + y[i]) & 1;
	}
	if (odd && even)
	{
		puts("-1");
		return 0;
	}
	if (even)
	{
		d[m = 1] = 1;
		for (int i = 1;i <= n;i++)
		{
			y[i]++;
			ans[i] += "D";
		}
	}
	for (int i = 30;i >= 0;i--)
		d[++m] = 1 << i;
	for (int i = 1;i <= n;i++)
		for (int j = 30;j >= 0;j--)
		{
			if (ok(j - 1,x[i] - (1 << j),y[i]))
			{
				x[i] -= 1 << j;
				ans[i] += "R";
			}
			else if (ok(j - 1,x[i] + (1 << j),y[i]))
			{
				x[i] += 1 << j;
				ans[i] += "L";
			}
			else if (ok(j - 1,x[i],y[i] - (1 << j)))
			{
				y[i] -= 1 << j;
				ans[i] += "U";
			}
			else
			{
				y[i] += 1 << j;
				ans[i] += "D";
			}
		}
	printf("%d\n",m);
	reverse(d + 1,d + m + 1);
	for (int i = 1;i <= m;i++)
		printf("%d ",d[i]);
	printf("\n");
	for (int i = 1;i <= n;i++)
	{
		reverse(ans[i].begin(),ans[i].end());
		puts(ans[i].c_str());
	}
	return 0;
}