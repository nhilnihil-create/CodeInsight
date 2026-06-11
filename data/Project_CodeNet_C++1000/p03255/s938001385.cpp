#include<cstdio>
#include<algorithm>
using namespace std;
#define LL long long
int a[200001];
LL sum[200001];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+a[i];
	LL ans=1LL<<62;
	for(int k=1;k<=n;k++){
		LL s=sum[k]*5;
		for(int i=k*2,j=2;;i+=k,j++){
			s+=(sum[min(i,n)]-sum[i-k])*(j*2+1);
			if(i>n||s>ans)break;
		}
		ans=min(ans,s+(LL)(k+n)*m);
	}
	printf("%lld",ans);
}
