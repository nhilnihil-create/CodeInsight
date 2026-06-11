#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define fo(i,a,b) for(i=a;i<=b;i++)
#define fd(i,a,b) for(i=a;i>=b;i--)
using namespace std;
const int N=200000,M=1000000500;
int i,j,n;
int a[N+5],now,sum,num,l,r,mid,top;
int z[N*100][2];
bool bz;
int read()
{
	int x=0;char s=getchar();
	while ((s<'0')||(s>'9')) s=getchar();
	while ((s>='0')&&(s<='9')) x=x*10+(s-'0'),s=getchar();
	return x;
}
bool dg(int x)
{
	num=0;now=0;bz=true;
	int i;
	top=0;
	fo(i,1,n)
	{
		if (a[i]<=now)
		{
			if (x==0) return false;
			bz=false;
			while (z[top][0]>a[i]) top--;
			if (z[top][0]<a[i]){top++;z[top][0]=a[i];z[top][1]=1;}
			else
			{
				while (top){
					if (z[top][1]<x)
					{
						z[top][1]++;
						bz=true;break;
					}
					if ((z[top][0]>1)&&(z[top][0]!=z[top-1][0]+1))
					{
						z[top][0]=z[top][0]-1;z[top][1]=1;
						bz=true;break;
					}
					top--;
				}
				if (!bz) return false;
			}
		}
		now=a[i];
		while (z[top][0]>now) top--;
	}
	return true;
}
int main()
{
	n=read();
	fo(i,1,n)a[i]=read();
	l=0;r=1000000;
	while (l<=r)
	{
		mid=(l+r)/2;
		if (dg(mid)){sum=mid;r=mid-1;}
		else l=mid+1;
	}
	printf("%d\n",sum+1);
	return 0;
}