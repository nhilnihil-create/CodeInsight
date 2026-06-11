#include <cmath>
#include <cstdio>
#include <algorithm>
typedef long long ll;

int T;
ll a,b;

int main()
{
	for(scanf("%d",&T);T--;)
	{
		scanf("%lld%lld",&a,&b);
		if(a>b)std::swap(a,b);
		ll s=a*b,c=sqrt(s),Ans;
		if(c*c==s)Ans=(c-1)*2-(a<c);
		else Ans=c*2-(c*(c+1)>=s)-(a<=c);
		printf("%lld\n",Ans);
	}
	return 0;
}