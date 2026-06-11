#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#define LL long long
using namespace std;
const LL inf=1e9;
LL a[200010],b[200010],sum=0,Min=inf,n;
int main()
{
	scanf("%lld",&n);
	for(LL i=1;i<=n;i++) scanf("%lld %lld",&a[i],&b[i]);
	bool flag=false;
	for(LL i=1;i<=n;i++)
	{
		if(a[i]!=b[i]) flag=true;
		sum+=a[i];if(a[i]>b[i]) Min=min(Min,b[i]);
	}
	if(!flag) printf("0");
	else printf("%lld",sum-Min);
}