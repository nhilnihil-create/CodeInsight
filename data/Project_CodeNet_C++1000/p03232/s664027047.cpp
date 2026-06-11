#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,mod=1e9+7;
int n;
long long ans;
int a[maxn],fact[maxn],inv[maxn],s[maxn];
int dec(int a,int b)
{
	return a-b<0?a-b+mod:a-b;
}
int Inv(int a)
{
	int b=mod-2,ans=1;
	while (b)
	{
		if (b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	fact[0]=1;
	for (int i=1;i<=n;i++)fact[i]=1ll*fact[i-1]*i%mod;
	for (int i=1;i<=n;i++)inv[i]=Inv(i),s[i]=(s[i-1]+inv[i])%mod;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		int s1=s[n-i+1],s2=dec(s[i],s[1]);
		int sum=(s1+s2)%mod;
		ans=(ans+1ll*a[i]*sum%mod)%mod;
	}
	printf("%lld",ans*fact[n]%mod);
	return 0;
}