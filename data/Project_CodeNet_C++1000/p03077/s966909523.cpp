#include<bits/stdc++.h>
using namespace std;
long long n ,a ,b ,c ,d ,e;
long long ans,minn=1e18;
int main()
{
	scanf("%lld%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d,&e);
	minn=min(a,min(b,min(c,min(d,e))));
    ans=(n-1)/minn+1 + 4;
	printf("%lld\n",ans);
	return 0;
}