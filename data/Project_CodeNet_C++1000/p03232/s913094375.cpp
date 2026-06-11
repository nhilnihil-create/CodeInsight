#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MaxN 100000+100
typedef long long ll;
const ll mod=1000000007;
ll A[MaxN];
ll inv[MaxN];
ll jc[MaxN];
ll my_pow(ll ds,ll cf)
{
	ll sum=1;
	while(cf>0)
	{
		if(cf%2==1)
			sum=(sum*ds)%mod;
		ds=(ds*ds)%mod;
		cf/=2;
	}
	return sum;
}
ll ny(ll num)
{
	return my_pow(num,mod-2);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&A[i]);
	inv[0]=0;
	jc[0]=1;
	for(int i=1;i<=n;i++)
	{
		inv[i]=(inv[i-1]+ny(i))%mod;
	//	printf("%d\n",ny(i)); 
		jc[i]=(jc[i-1]*i)%mod;
	}
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		int z=i;
		int y=n-i+1;
		ll resu=(inv[z]+inv[y]-inv[1]+mod)%mod;
		resu=(resu*A[i])%mod;
		sum=(sum+resu)%mod;
	//	printf("%d-%d-%d %lld\n",A[i],z,y,resu);
	}
	sum=(sum*jc[n])%mod;
	printf("%lld\n",sum);
	return 0;
 } 