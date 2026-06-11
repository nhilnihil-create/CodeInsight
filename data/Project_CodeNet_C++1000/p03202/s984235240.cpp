#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <bitset>
using namespace std;
const int maxn=200010;

int n,top,a[maxn];
struct node{
	int w,a;
}zhan[maxn];
bool bz;

void doit(int p,int q)
{
	if (p==0)
	{
		bz=false;
		return;
	}
	while (zhan[top].w>p)
	{
		top--;
	}
	if (zhan[top].w==p) zhan[top].a++;
	else 
	{
		top++;
		zhan[top].w=p;
		zhan[top].a=2;
	}
	if (zhan[top].a==q+1)
	{
		if (top>0)
		{
			top--;
			doit(p-1,q);
		}
	}
}

bool pd(int x)
{
	top=0;zhan[0].w=0;
	bz=true;
	for (int i=1;i<=n;i++)
	{
		if (a[i]<=a[i-1])
		{
			doit(a[i],x);
		}
	}
	return bz;
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	
	int l=2;
	int r=100000000;
	int ans=0;
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (pd(mid))
		{
			ans=mid;
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	int k=0;
	for (int i=1;i<n;i++)
	{
		if (a[i]>=a[i+1])
		{
			k=1;
		}
	}
	if (k==0) ans=1;
	printf("%d\n",ans);
}