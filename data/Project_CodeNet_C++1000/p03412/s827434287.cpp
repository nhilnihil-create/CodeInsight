//Zory-2018
//*******************头文件*******************
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long ll;
//*******************全局常量*******************
const int MAXN=210000;
//*******************全局定义*******************
ll q[MAXN],w[MAXN];
ll bin[35];
int n;
//*******************实现*******************
/*
debug
bool cmp(ll a,ll b)
{
	return (a%bin[f+1])<(b%bin[f+1]);
}*/
//*******************主函数*******************
ll w2[MAXN];
int main()
{
	bin[0]=1;for(int i=1;i<=32;i++) bin[i]=bin[i-1]<<1;

	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&q[i]);
	for(int i=1;i<=n;i++) scanf("%lld",&w[i]);

	ll ans=0;
	for(int f=0;f<=29;f++)
	{
		for(int i=1;i<=n;i++) w2[i]=w[i]%bin[f+1];
        sort(w2+1,w2+1+n);

		ll t=0;
		for(int i=1;i<=n;i++)
		{
			ll now=q[i]%bin[f+1],ss=0;
			ll l,r;
			int bf;

			l=bin[f];r=bin[f+1]-1;
            l=lower_bound(w2+1,w2+n+1,l-now)-w2;
            r=upper_bound(w2+1,w2+n+1,r-now)-w2-1;
			bf=r-l+1;if(bf>0) ss+=bf;

			l=bin[f+1]+bin[f];r=bin[f+2]-1;
            l=lower_bound(w2+1,w2+n+1,l-now)-w2;
            r=upper_bound(w2+1,w2+n+1,r-now)-w2-1;
			bf=r-l+1;if(bf>0) ss+=bf;

			t=(t+ (ss&1) )&1;
		}
		ans+=(t<<f);
	}
	printf("%lld",ans);
}
