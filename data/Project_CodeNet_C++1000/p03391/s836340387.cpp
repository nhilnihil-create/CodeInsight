#include<cstdio>
#include<algorithm>
using namespace std;
int n;
long long a,b,t=1000000001,ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&a,&b);
		ans+=a;
		if(a>b)
		t=min(t,b);
	}
	if(t==1000000001)
		printf("0");
	else printf("%lld",ans-t);
}
