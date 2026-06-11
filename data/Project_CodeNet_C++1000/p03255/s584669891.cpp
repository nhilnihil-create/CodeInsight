#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,x,a[N],e[N];
ll sum[N],ans,s;
int main()
{
	scanf("%d%d",&n,&x);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	reverse(a+1,a+n+1);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	e[1]=e[2]=5;
	for (int i=3;i<=n;i++) e[i]=e[i-1]+2;
	ans=1e18;
	for (int k=1;k<=n;k++)//取k次 
	{
		s=(ll)(n+k)*x;
		for (int i=1,cnt=1;i<=n;i+=k,cnt++)
		{
		    s+=(ll)(sum[min(i+k-1,n)]-sum[i-1])*e[cnt];
			if (s>ans) break;
		}
		ans=min(ans,s);
	}
	printf("%lld\n",ans);
	return 0;
}