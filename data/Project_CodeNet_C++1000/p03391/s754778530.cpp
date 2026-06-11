#include<cstdio>
#include<algorithm>
#include<climits>
#include<queue>
using namespace std;
long long n,ans,a,b,sum,mi;
#define inf 1e18
int main()
{
	scanf("%lld",&n);
	mi=inf;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a,&b);
		sum+=a;
		if(a>b)
			mi=min(mi,b);
	}
	printf("%lld\n",mi==inf?0:sum-mi);
	return 0;
}