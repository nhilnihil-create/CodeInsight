#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,v[5005];
ll a,b,f[5005];
int main()
{
	scanf("%d%lld%lld",&n,&a,&b);
	for(int i=1;i<=n+1;i++)
	{
		f[i]=1000000000000000000;
		if(i<=n)scanf("%d",&v[i]);
		else v[i]=n+1;
		ll sum=0;
		int maxx=0;
		for(int j=i-1;j>=1;j--)
		{
			if(v[j]>v[i])sum+=a;
			else if(v[j]>maxx)
			{
				f[i]=min(f[i],f[j]+sum);
				sum+=b;
			}
			else sum+=b;
		}
		f[i]=min(f[i],sum);
	}
	printf("%lld\n",f[n+1]);
	return 0;
}