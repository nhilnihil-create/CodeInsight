//题目：有n(n<=3*1e5)个格子，每个格子可以选择涂成红色、蓝色、绿色或不涂色，
//三种颜色分别产生a,b,a+b(a,b<=3*1e5)的收益。问有多少种涂色方案使得总收益为 k(k<=18*1e10)。
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;

const int MOD=998244353;
const int N=3e5+5;
long long inv[N],finv[N],k[N];

void init()
{
	k[0]=k[1]=1;
	for(int i=2;i<=300000;i++){
		k[i]=k[i-1]*i%MOD;
	}
	inv[1]=1;
	for(int i=2;i<=300000;i++){
		inv[i]=(MOD-MOD/i*inv[MOD%i]%MOD)%MOD; 
	}
	finv[0]=finv[1]=1;
	for(int i=2;i<=300000;i++){
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
}

int main()
{
	ll n,a,b,d,x,y,s;
	scanf("%lld%lld%lld%lld",&n,&a,&b,&s);
	init();
	ll ans=0;
	for(int i=0;i<=n;i++){
		if(i*a>s)break;
		ll j=s-i*a;
		if(j/b>n)continue;
		if(j%b==0){
			j/=b;
			ans=(ans+k[n]*finv[i]%MOD*finv[n-i]%MOD*k[n]%MOD*finv[j]%MOD*finv[n-j]%MOD)%MOD;
		}
	}
	printf("%lld",ans);
	
	return 0;
}