#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
#define m_k make_pair
#define mod 998244353
#define int long long
using namespace std;
const int N=1e6+100;
int n,a,b,k,fac[N],inv[N],ans;
int C(int n,int m){return fac[n]*inv[m]%mod*inv[n-m]%mod;}
void add(int &a,int b){a=(a+b)%mod;}
int m_pow(int a,int b)
{
	int ans=1;
	while (b)
	{
		if (b&1) ans=(ans*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return ans;
}
signed main()
{
	scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
	fac[0]=1;
	for (int i=1;i<=3*n;i++) fac[i]=(fac[i-1]*i)%mod;
	inv[3*n]=m_pow(fac[3*n],mod-2);
	for (int i=3*n-1;i>=0;i--) inv[i]=(inv[i+1]*(i+1))%mod;
	for (int i=0;i<=n;i++)
	{
		if (i*a>k) break;
		if ((k-i*a)%b!=0) continue;
		int j=(k-i*a)/b,k=max(i+j-n,0ll);
		if (k>min(i,j) || k>n) continue;
		// printf("%lld %lld %lld\n",i,j,k);
		// printf("%lld %lld %lld\n",C(n,k),C(n-k,i-k),C(n-k,j-k));
		add(ans,C(n,i)*C(n,j)%mod);
		// printf("%lld\n",ans);
	}
	printf("%lld\n",ans);
}