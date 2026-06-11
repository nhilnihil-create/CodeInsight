#include<cstdio>
#include<string>
#include<cstring>
#include<utility>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
#include<vector>
#include<iostream>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define inf 0x7fffffff
using namespace std;
int a[100];
int main()
{
	int i,j,k,n,m=1;
	ll x,y;
	scanf("%d%lld",&n,&x);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&y);
		j=0;
		while(y>0)
		{
			a[j]+=y&1;
			y=y>>1;
			j++;
		}
		m=max(m,j);
	}
	j=0;
	ll x1=x;
	while(x>0)
	{
		x=x>>1;
		j++;
	}
	m=max(m,j);
	x=x1;
	bool bo=0;
	for(i=m-1;i>=0;i--)
	{
		if(bo)
		{
			if(a[i]<n-a[i])
			{
				a[i]=n-a[i];
			}
		}
		else
		{
			if(a[i]<n-a[i])
			{
				if((x>>i)&1)
				{
					a[i]=n-a[i];
				}
			}
			else
			{
				if((x>>i)&1)
				{
					bo=1;
				}
			}
		}
	}
	ll ans=0;
	for(i=m-1;i>=0;i--)
	{
		ans+=1ll*a[i]*(1ll<<i);
	}
	printf("%lld",ans);
	return 0;
}
