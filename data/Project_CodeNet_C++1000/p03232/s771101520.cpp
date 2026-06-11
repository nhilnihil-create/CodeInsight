#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define MN 100005
using namespace std;
typedef long long ll;
int n,inv[MN],sum[MN],a[MN];
ll ans;
const int mod=1e9+7;
int main(){
	scanf("%d",&n);inv[0]=inv[1]=1;
	for(int i=2;i<=n;i++)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+inv[i],sum[i]%=mod;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),ans+=1ll*a[i]*(sum[i]+sum[n-i+1]-1)%mod,ans%=mod;
	for(int i=1;i<=n;i++)ans=1ll*ans*i%mod;
	printf("%lld\n",ans);
}
