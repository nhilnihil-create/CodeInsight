#pragma GCC optimize (2)
#pragma G++ optimize (2)
#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 1005
using namespace std;
//char nc()
//{
//	static char buf[100000],*p1=buf,*p2=buf;
//	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
//}
char nc(){return getchar();}
int read()
{
	int x=0,y=1;
	char c=nc();
	while(!isdigit(c))
	{
		if(c=='-')y=-1;
		c=nc();
	}
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=nc();
	}
	return x*y;
}
int n,x[MAX],y[MAX];
int bin[35];
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
		x[i]=read(),y[i]=read();
	int type=(abs(x[1]+y[1])&1);
	for(int i=2;i<=n;i++)
		if((abs(x[i]+y[i])&1)!=type)
			return puts("-1"),0;
	bin[0]=1;
	for(int i=1;i<=30;i++)
		bin[i]=bin[i-1]<<1;
	if(!type)
		puts("32"),printf("1 ");
	else
		puts("31");
	for(int i=30;i>=0;i--)
		printf("%d ",bin[i]);
	putchar('\n');
	for(int i=1;i<=n;i++)
	{
		long long nx=0,ny=0;
		if(!type) nx++,putchar('R');
		for(int j=30;j>=0;j--)
		{
			long long tx=x[i]-nx,ty=y[i]-ny;
			if(abs(tx)>abs(ty))
			{
				if(tx>0) nx+=bin[j],putchar('R');
				else nx-=bin[j],putchar('L');
			}
			else
			{
				if(ty>0) ny+=bin[j],putchar('U');
				else ny-=bin[j],putchar('D');
			}
		}
		putchar('\n');
	}
	return 0;
}
