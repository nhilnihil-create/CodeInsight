//Love and Freedom.
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
#define inf 20021225
#define N 1225
using namespace std;
int read()
{
	int s=0,t=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')	t=-1; ch=getchar();}
	while(ch>='0' && ch<='9')	s=s*10+ch-'0',ch=getchar();
	return s*t;
}
int d[N],m,x[N],y[N],n;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		x[i]=read(),y[i]=read();
		if(((x[i]+y[i])&1)!=((x[1]+y[1])&1))	return puts("-1"),0;
	}
	if(!((x[1]+y[1])&1))	d[++m]=1;
	for(int i=30;~i;i--)	d[++m]=(1<<i);
	printf("%d\n",m);
	for(int i=1;i<=m;i++)	printf("%d ",d[i]); puts("");
	for(int i=1;i<=n;i++,puts(""))
	{
		for(int j=1;j<=m;j++)
		{
			if(abs(x[i])>abs(y[i]))
			{
				if(x[i]>0)	x[i]-=d[j],putchar('R');
				else	x[i]+=d[j],putchar('L');
			}
			else
			{
				if(y[i]>0)	y[i]-=d[j],putchar('U');
				else	y[i]+=d[j],putchar('D');
			}
		}
	}
	return 0;
}