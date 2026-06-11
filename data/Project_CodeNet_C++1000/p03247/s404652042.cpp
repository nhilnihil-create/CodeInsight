#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
using namespace std;
inline int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-')
		c=getchar();
	if(c=='-')
		c=getchar(),x=-1;
	while(c>='0' && c<='9')
		kkk=(kkk<<3)+(kkk<<1)+(c-'0'),c=getchar();
	return kkk*x;
}
int n,zone[1001][2],F,maxn,ans[41],d[41];
inline void solve(int &zone,int &bj,int &ans,int reduce,int type)
{
	if(zone<0)
	{
		zone=-zone;
		bj^=1;
	}
	zone-=reduce;
	ans=type-bj;
}
inline void print(int p)
{
	switch(p)
	{
		case 0:putchar('D');break;
		case 1:putchar('U');break;
		case 2:putchar('L');break;
		case 3:putchar('R');break;
	}
}
int main()
{
	n=read();
	for(register int i=1;i<=n;++i)
	{
		zone[i][0]=read();
		zone[i][1]=read();
		maxn=max(abs(zone[i][0])+abs(zone[i][1]),maxn);
	}
	for(register int i=2;i<=n;++i)
		if((abs(zone[i][0])+abs(zone[i][1]))%2!=(abs(zone[i-1][0])+abs(zone[i-1][1]))%2)
		{
			puts("-1");
			return 0;
		}
	if((zone[1][0]+zone[1][1])%2==0)
	{
		F=1;
		--maxn;
	}
	int LOG=ceil(log2(maxn+1))-1;
	printf("%d\n",LOG+1+F);
	d[0]=1;
	for(register int i=0;i<=LOG;++i,d[i]=d[i-1]*2)
		printf("%d ",d[i]);
	if(F)
		putchar('1');
	putchar('\n');
	for(register int i=1;i<=n;++i)
	{
		int x=zone[i][0],y=zone[i][1],mem=-1,bjx=0,bjy=0;
		if(F)
		{
			if(abs(x)>abs(y))
				solve(x,bjx,mem,1,3);
			else
				solve(y,bjy,mem,1,1);
		}
		for(register int j=LOG;j>=0;--j)
			if(abs(x)>abs(y))
				solve(x,bjx,ans[j],d[j],3);
			else
				solve(y,bjy,ans[j],d[j],1);
		for(register int j=0;j<=LOG;++j)
			print(ans[j]);
		if(F)
			print(mem);
		putchar('\n');
	}
	return 0;
}