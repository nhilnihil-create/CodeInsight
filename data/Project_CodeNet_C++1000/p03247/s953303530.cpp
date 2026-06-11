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
			int type=(abs(x)>abs(y));
			if(type)
			{
				if(x<0)
				{
					x=-x;
					bjx^=1;
				}
				x-=1;
				mem=3;
				if(bjx)
					mem=2;
			}
			else
			{
				if(y<0)
				{
					y=-y;
					bjy^=1;
				}
				y-=1;
				mem=0;
				if(bjy)
					mem=1;
			}
		}
		//cout<<bjx<<" "<<bjy<<endl;
		for(register int j=LOG;j>=0;--j)
		{
			int type=(abs(x)>abs(y));
			if(type)
			{
				if(x<0)
				{
					x=-x;
					bjx^=1;
				}
				x-=d[j];
				ans[j]=3;
				if(bjx)
					ans[j]=2;
			}
			else
			{
				if(y<0)
				{
					y=-y;
					bjy^=1;
				}
				y-=d[j];
				ans[j]=0;
				if(bjy)
					ans[j]=1;
			}
		}
		for(register int j=0;j<=LOG;++j)
			switch(ans[j])
			{
				case 0:putchar('U');break;
				case 1:putchar('D');break;
				case 2:putchar('L');break;
				case 3:putchar('R');break;
			}
		if(F)
			switch(mem)
			{
				case 0:putchar('U');break;
				case 1:putchar('D');break;
				case 2:putchar('L');break;
				case 3:putchar('R');break;
			}
		putchar('\n');
	}
	return 0;
}