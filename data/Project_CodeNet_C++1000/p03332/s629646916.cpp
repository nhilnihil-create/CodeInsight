//Love and Freedom.
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
#define inf 20021225
#define mdn 998244353
#define N 900010 
using namespace std;

int a,b,n; ll k;
int fac[N],inv[N];
int ksm(int bs,int mi)
{
	int ans=1;
	while(mi)
	{
		if(mi&1)
			ans=(ll)ans*bs%mdn;
		bs=(ll)bs*bs%mdn; mi>>=1;
	}
	return ans;
}
int C(int n,int m)
{
	if(n<m)	return 0;
	return (ll)fac[n]*inv[m]%mdn*inv[n-m]%mdn;
}
void upd(int &x,int y){x=(x+y)%mdn;} 
int main()
{
	int ans=0;
	scanf("%d%d%d%lld",&n,&a,&b,&k);
	fac[0]=inv[0]=1;
	for(int i=1;i<=n;i++)	fac[i]=(ll)fac[i-1]*i%mdn;
	inv[n]=ksm(fac[n],mdn-2);// printf("%d\n",inv[n]);
	for(int i=n-1;i;i--)	inv[i]=(ll)inv[i+1]*(i+1)%mdn;
	for(int i=0;i<=n&&(ll)i*a<=k;i++)
	{
		if((k-a*i)%b==0)
		{
			ll bi=(k-a*i)/b;
			upd(ans,(ll)C(n,i)*C(n,bi)%mdn);
		}
	}
	printf("%d\n",ans);
	return 0;
}
/**
300000 300000 300000 0
*/
