#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[111111],mn;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	mn=1;
	for (int i=2;i<n;i++)
	{
		if (max(a[i],a[n]-a[i])<max(a[mn],a[n]-a[mn])) mn=i;
	}
	printf("%d %d\n",a[n],a[mn]);
	return 0;
}