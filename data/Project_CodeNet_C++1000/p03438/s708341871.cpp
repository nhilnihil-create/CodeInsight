#include<iostream>
#include<cstdio>
#define N 12345
#define ll long long
using namespace std;
ll n,a[N],b[N],sum1,sum2;
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) scanf("%lld",a+i);
	for(ll i=1;i<=n;i++) scanf("%lld",b+i);
	for(ll i=1;i<=n;i++)
	{
		if(a[i] > b[i]) sum1 += (a[i] - b[i]);
		if(a[i] < b[i]) sum2 += (b[i] - a[i])/2;
	}
	if(sum1>sum2) puts("No");
	else puts("Yes");
	return 0;
}