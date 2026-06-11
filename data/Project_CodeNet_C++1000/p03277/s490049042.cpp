#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int bit[N*2],a[N],s[N],n;
int sum(int i)
{
	int s=0;
	while(i)
	{
		s+=bit[i];
		i-=i&-i;
	}
	return s;
}
void add(int i,int x)
{
	while(i<=200000)
	{
		bit[i]+=x;
		i+=i&-i;	
	}	
}
int check(int x)
{
	memset(bit,0,sizeof(bit));
	s[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>=x)
			s[i]=s[i-1]+1;
		else
			s[i]=s[i-1]-1;
	}
	long long tot=0;
	for(int i=0;i<=n;i++)
	{
		tot+=sum(s[i]+100000);
		add(s[i]+100000,1);
	}
	if(tot>=1LL*n*(n+1)/4)
		return 1;
	else
		return 0;
}
int main()
{
	int lb=0,ub=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		ub=max(ub,a[i]+1);
	}
	while(ub-lb>1)
	{
		int mid=(lb+ub)>>1;
		if(check(mid))
			lb=mid;
		else
			ub=mid;
	}
	printf("%d\n",lb);
	return 0;
}
