#include <bits/stdc++.h>
using namespace std;
int n;
int get(int now)
{
	++now;
	while (now%2!=0&&now%3!=0) ++now;
	return now;
}
int main()
{
	scanf("%d",&n);
	if (n==3)
	{
		printf("%d %d %d\n",2,5,63);
		return 0;
	}
	int s=0,now=0;
	for (int i=1;i<=n-2;i++)
	{
		now=get(now);
		s=(s+now)%6;
		printf("%d ",now);
	}
	++now;
	if (s==0)
	{
		while (now%6!=0) ++now;
		printf("%d %d\n",now,now+6);
	} else if (s==1)
	{
		while (now%6!=2) ++now;
		printf("%d %d\n",now,now+1);
	} else if (s==2)
	{
		while (now%6!=4) ++now;
		printf("%d %d\n",now,now+2);
	} else if (s==3)
	{
		while (now%6!=3) ++now;
		printf("%d %d\n",now,now+3);
	} else if (s==4)
	{
		while (now%6!=2) ++now;
		printf("%d %d\n",now,now+6);
	} else if (s==5)
	{
		while (now%6!=3) ++now;
		printf("%d %d\n",now,now+1);
	}
	return 0;
}
