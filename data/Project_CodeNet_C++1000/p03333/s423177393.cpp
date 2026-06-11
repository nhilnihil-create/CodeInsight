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

const int MAXN = 300005;

struct Seg
{
	int l,r,id;
}sl[MAXN],sr[MAXN];

int n;

long long ans;

bool mark[MAXN];

bool cmp1(const Seg &a,const Seg &b)
{
	return a.l > b.l;
}

bool cmp2(const Seg &a,const Seg &b)
{
	return a.r < b.r;
}

void run()
{
	memset(mark,0,sizeof(mark));
	int p = 0;
	long long res = 0;
	for (int i = 1,j = 1,k = 1;i <= n;i++)
	{
		if (i & 1)
		{
			while (mark[sl[j].id])
				j++;
			mark[sl[j].id] = 1;
			res += max(0,sl[j].l - p);
			p = max(p,sl[j].l);
			j++;
		}
		else
		{
			while (mark[sr[k].id])
				k++;
			mark[sr[k].id] = 1;
			res += max(0,p - sr[k].r);
			p = min(p,sr[k].r);
			k++;
		}
	}
	ans = max(ans,res + abs(p));
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d%d",&sl[i].l,&sl[i].r);
		sl[i].id = i;
		sr[i] = sl[i];
	}
	sort(sl + 1,sl + n + 1,cmp1);
	sort(sr + 1,sr + n + 1,cmp2);
	run();
	for (int i = 1;i <= n;i++)
	{
		sl[i].l = -sl[i].l;
		sl[i].r = -sl[i].r;
		swap(sl[i].l,sl[i].r);
		sr[i] = sl[i];
	}
	sort(sl + 1,sl + n + 1,cmp1);
	sort(sr + 1,sr + n + 1,cmp2);
	run();
	printf("%lld\n",ans);
	return 0;
}