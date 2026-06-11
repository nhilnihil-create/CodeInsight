#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<sstream>
#include<bitset>
#define scand(a) scanf("%d",&a)
#define scandd(a,b) scanf("%d%d",&a,&b)
#define scanddd(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define mst(a,b) memset(a,b,sizeof(a))
#define lowbit(x) (x&-x)
#define lson rt<<1
#define rson rt<<1|1
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3fLL;
const int maxn=1e5+5;
const ll mod=1e9+7;
ll inv[maxn],sum[maxn];
ll a[maxn];
void init()
{
	inv[0]=0;inv[1]=1;
	for(int i=2;i<maxn;i++)
	{
		inv[i]=(mod-mod/i)%mod*inv[mod%i]%mod;
	}
	for(int i=1;i<maxn;i++)
	{
		sum[i]=(inv[i]+sum[i-1])%mod;
	}
}
int main()
{
	#ifdef local
	freopen("1.txt","r",stdin);
	#endif
	init();
	int n;
	scand(n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		ans=(ans+a[i]*(sum[n-i+1]+sum[i]-1)%mod)%mod;
	}
	for(int i=1;i<=n;i++)
	{
		ans=(ans*i)%mod;
	}
	printf("%lld",ans);
}