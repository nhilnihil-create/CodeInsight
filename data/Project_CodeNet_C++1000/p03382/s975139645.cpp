#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,x,a[100010];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	x=a[1];
	for(int i=2;i<=n-1;i++)
	{
		int y=min(a[i],a[n]-a[i]),k=min(x,a[n]-x);
		if(y>k) x=a[i];
	}
	printf("%d %d",a[n],x);
}