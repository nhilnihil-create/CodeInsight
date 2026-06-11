#include<cstdio>
#define min(a,b) a<b?a:b
typedef long long LL;
int main()
{
	LL a,b,T,ans=0;
	bool flag=0;
	LL mi=1111111111;
	scanf("%lld",&T);
	while(T--) {
		scanf("%lld%lld",&a,&b);
		if(a!=b) flag=1;
		ans+=a;
		if(a>b)
			mi=min(b,mi);
	}
	if(!flag)
		ans=mi;
	printf("%lld",ans-mi);
}//