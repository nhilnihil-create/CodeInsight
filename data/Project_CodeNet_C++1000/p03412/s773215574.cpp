#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[200010],b[200010],n,c[200010];
int num[30];
int get1(int k)
{
	int l=1,r=n,ans=n+1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(c[mid]>=k) ans=mid,r=mid-1;
		else l=mid+1;
	}
	return ans;
}
int get2(int k)
{
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(c[mid]<k) ans=mid,l=mid+1;
		else r=mid-1;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	int T=1;
	for(int I=0;I<29;I++)
	{
		int t=(1<<(I+1))-1;
		for(int i=1;i<=n;i++) c[i]=b[i]&t;
		sort(c+1,c+n+1);
		for(int i=1;i<=n;i++)
		{
			int x=a[i]&t;
			int l=get1(T-x),r=get2(2*T-x);
			if(l<=r) num[I]+=(r-l+1);
			l=get1(3*T-x);r=get2(4*T-x);
			if(l<=r) num[I]+=(r-l+1);
		}
		T<<=1;
	}
	int ans=0;
	for(int i=0;i<29;i++) if(num[i]&1) ans+=(1<<i);
	printf("%d",ans);
}