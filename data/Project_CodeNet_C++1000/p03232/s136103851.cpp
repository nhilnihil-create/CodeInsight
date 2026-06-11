//https://agc028.contest.atcoder.jp/tasks/agc028_b
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,i,j,a[100005],inv[100005],ans=0; 
const ll mod=1e9+7;
int main()
{
	scanf("%lld",&n);
	for(i=1;i<=n;i++)scanf("%lld",&a[i]);
	inv[1]=1;
	for(i=2;i<=n;i++)inv[i]=(-inv[mod%i]*(mod/i)%mod+mod)%mod;
	for(i=2;i<=n;i++)inv[i]=(inv[i-1]+inv[i])%mod;
	for(i=1;i<=n;i++)ans=(ans+a[i]*(inv[i]+inv[n-i+1]-1+mod)%mod)%mod;
	for(i=1;i<=n;i++)ans=ans*i%mod;
	printf("%lld",ans);
}
