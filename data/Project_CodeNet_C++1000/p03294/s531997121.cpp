#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int num[5000],n;
long long ans = 0;
int max(int a,int b)
{
	return a>b?a:b;
}
int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int i,j,k,maxn = 0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		ans += num[i];
	}
	ans -= n;
	printf("%lld",ans);  
	return 0;
}