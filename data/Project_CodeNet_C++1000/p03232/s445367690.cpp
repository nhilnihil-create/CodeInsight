#include<cstdio>
#define RI register int
#define CI const int&
using namespace std;
const int N=100005,mod=1e9+7;
int n,a[N],fn,inv[N],ans;
int main()
{
	RI i; for (scanf("%d",&n),i=1;i<=n;++i) scanf("%d",&a[i]);
	for (fn=inv[0]=inv[1]=1,i=2;i<=n;++i)
	inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
	for (i=2;i<=n;++i) fn=1LL*fn*i%mod,(inv[i]+=inv[i-1])%=mod;
	for (i=1;i<=n;++i) (ans+=1LL*(inv[i]+inv[n-i+1]-1)*fn%mod*a[i]%mod)%=mod;
	return printf("%d",ans),0;
}