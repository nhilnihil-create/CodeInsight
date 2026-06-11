#pragma GCC optimize (2)
#pragma G++ optimize (2)
#include<bits/stdc++.h>
#define INF (1ll<<61)
#define MAX 5005
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
int n,a[MAX];
long long A,B,f[MAX];
int main()
{
	n=read();A=read();B=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	a[0]=0;a[n+1]=n+1;
	f[0]=0;
	for(int i=1;i<=n+1;i++)
	{
		int s1=0,s2=0;
		f[i]=INF;
		for(int j=i-1;j>=0;j--)
		{
			if(a[j]<a[i]) f[i]=min(f[i],f[j]+A*s1+B*s2),s2++;
			else s1++;
		}
	}
	printf("%lld",f[n+1]);
	return 0;
}
