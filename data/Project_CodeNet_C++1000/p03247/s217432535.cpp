#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
int x[1050],y[1050];
char ans[1050][35];
int ln[1005],suf[35];
int seq[35],sc;

long long getmanhattan(long long xx,long long yy,long long xxx,long long yyy)
{
	return abs(xx - xxx) + abs(yy - yyy);
}

signed main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n; ++ i) scanf("%d%d",&x[i],&y[i]);
	for(int i = 2;i <= n; ++ i)
		if(abs((x[i] + y[i]) % 2) != abs((x[i - 1] + y[i - 1]) % 2))
		{
			printf("-1\n");
			return 0;
		}
	if((x[1] + y[1]) % 2 == 0)
	{
		seq[++ sc] = 1;
		for(int i = 1;i <= n; ++ i)
		{
			y[i] --;
			ans[i][ln[i] ++] = 'U'; 
		}
	}
	suf[1] = 1;
	for(int i = 2;i <= 31; ++ i)
		suf[i] = suf[i - 1] * 2;
	int st = sc + 1;
	for(int i = 31;i >= 1; -- i)
		seq[++ sc] = suf[i];
	reverse(suf + 1,suf + 1 + 31);
	for(int i = 30;i >= 1; -- i) suf[i] += suf[i + 1];
	for(int p = 1;p <= n; ++ p)
	{
		int curx = 0,cury = 0;
		for(int i = st;i <= sc; ++ i)
		{
			curx += seq[i];
			if(getmanhattan(curx,cury,x[p],y[p]) <= suf[i - st + 2])
			{
				ans[p][ln[p] ++] = 'R';
				continue;
			}
			curx -= 2 * seq[i];
			if(getmanhattan(curx,cury,x[p],y[p]) <= suf[i - st + 2])
			{
				ans[p][ln[p] ++] = 'L';
				continue;
			}
			curx += seq[i];
			cury += seq[i];
			if(getmanhattan(curx,cury,x[p],y[p]) <= suf[i - st + 2])
			{
				ans[p][ln[p] ++] = 'U';
				continue;
			}
			cury -= 2 * seq[i];
			ans[p][ln[p] ++] = 'D';
		}
		if(curx != x[p] || cury != y[p]) printf("FUCK\n");
	}
	printf("%d\n",sc);
	for(int i = 1;i <= sc; ++ i)
		printf("%d ",seq[i]);
	printf("\n");
	for(int i = 1;i <= n; ++ i)
		printf("%s\n",ans[i]);
}