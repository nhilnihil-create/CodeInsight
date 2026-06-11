#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<queue>
#include<bitset>
#include<complex>
#include<cmath>
using namespace std;
template<typename __T>
inline void read(__T &x)
{
    x=0;
    int f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')	f=-1;c=getchar();}
    while(isdigit(c))	{x=x*10+c-'0';c=getchar();}
    x*=f;
}
int n,a,b;
int s[300005];
int blo[300005];
int main()
{
	read(n);
	read(a);
	read(b);
	if(n==1)
	{
		if(a==1 && b==1)
			printf("1\n");
		else
			printf("-1\n");
		return 0;
	}
	if(a==1)
	{
		if(b==n)
			for(int i=n;i>=1;i--)
				printf("%d ",i);
		else
			printf("-1");
		printf("\n");
		return 0;
	}
	if(b==1)
	{
		if(a==n)
			for(int i=1;i<=n;i++)
				printf("%d ",i);
		else
			printf("-1");
		printf("\n");
		return 0;
	}
	if(a+b>n+1)
	{
		printf("-1\n");
		return 0;
	}
	if(a+b==n+1)
	{
		for(int i=n-a+1;i<=n;i++)
			printf("%d ",i);
		for(int i=n-a;i>=1;i--)
			printf("%d ",i);
		return 0;
	}
	if(1ll*a*b<n)
	{
		printf("-1\n");
		return 0;
	}
	int rem=n;
	for(int i=1;i<=b;i++)
	{
		blo[i]++;
		rem--;
	}
	for(int i=1;i<=b;i++)
	{
		if(rem==0)	break;
		while(blo[i]!=a && rem)
		{
			blo[i]++;
			rem--;
		}
	}
	rem=-1;
	for(int i=1;i<=b;i++)
	{
		for(int j=n-rem-blo[i];j<n-rem;j++)
			printf("%d ",j);
		rem+=blo[i];
	}
	printf("\n");
	return 0;
}