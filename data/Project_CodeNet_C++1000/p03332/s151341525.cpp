//压行课次
#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int MAXN=3e5+10;
LL n,A,B,K,fac[MAXN],invl[MAXN],ans,mod=998244353;
LL read(){LL sss=0,fff=1;char ccc;ccc=getchar();while(ccc<'0'||ccc>'9'){if(ccc=='-')fff=-1;ccc=getchar();}while(ccc>='0'&&ccc<='9')sss=(sss<<1)+(sss<<3)+(ccc^'0'),ccc=getchar();return sss*fff;}
LL ksm(LL base,LL k)
{
	LL sum=1;
	while(k)
	{
		if(k&1) sum=sum*base%mod;
		base=base*base%mod;
		k>>=1;
	}
	return sum;
}
LL C(LL a,LL b)
{
	if(a<b) return 0ll;
	return fac[a]*invl[b]%mod*invl[a-b]%mod;
}
int main()
{
//	freopen("123.in","r",stdin);
//	freopen("123.out","w",stdout);
	n=read();A=read();B=read();K=read();
	fac[0]=1;for(LL i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	invl[n]=ksm(fac[n],mod-2);for(LL i=n-1;i>=0;i--) invl[i]=invl[i+1]*(i+1)%mod;
	for(LL i=0;;i++)
	{
		if(A*i>K) break;
		if((K-A*i)%B==0) 
		{
			LL b=(K-A*i)/B;
			ans=(ans+C(n,i)*C(n,b)%mod)%mod;
		}
	}
	printf("%lld\n",ans);
    return 0;
}