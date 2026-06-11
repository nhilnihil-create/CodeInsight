#include <cstdio>
#include <algorithm>
typedef long long ll;

const int Inf=0x3f3f3f3f;
int n,a,b,Mb=Inf;
ll Sum;

int main()
{
	for(scanf("%d",&n);n--;)
	{
		scanf("%d%d",&a,&b),Sum+=b;
		if(a>b)Mb=std::min(Mb,b);
	}
	Sum-=Mb;
	if(Mb==Inf)Sum=0;
	printf("%lld\n",Sum);
	return 0;
}