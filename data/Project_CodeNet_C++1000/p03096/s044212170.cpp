#include<bits/stdc++.h>
#define del(a,i) memset(a,i,sizeof(a))
#define ll long long
#define inl inline
#define il inl void
#define it inl int
#define ill inl ll
#define re register
#define ri re int
#define rl re ll
#define mid ((l+r)>>1)
#define lowbit(x) (x&(-x))
#define INF 0x3f3f3f3f
using namespace std;
template<class T>il read(T &x){
	int f=1;char k=getchar();x=0;
	for(;k>'9'||k<'0';k=getchar()) if(k=='-') f=-1;
	for(;k>='0'&&k<='9';k=getchar()) x=(x<<3)+(x<<1)+k-'0';
	x*=f;
}
template<class T>il _print(T x){
	if(x/10) _print(x/10);
	putchar(x%10+'0');
}
template<class T>il print(T x){
	if(x<0) putchar('-'),x=-x;
	_print(x);
}
ll mul(ll a,ll b,ll mod){long double c=1.;return (a*b-(ll)(c*a*b/mod)*mod)%mod;}
it qpow(int x,int m,int mod){
	int res=1,bas=x%mod;
	while(m){
		if(m&1) res=(1ll*res*bas)%mod;
		bas=(1ll*bas*bas)%mod,m>>=1;
	}
	return res%mod;
}
const int MAXN = 2e5+5,mod = 1e9+7;
int n,val[MAXN],pre[MAXN],dp[MAXN];
it add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n),dp[0]=1;
	for(ri i=1;i<=n;++i) read(val[i]);
	for(ri i=1;i<=n;++i){
		dp[i]=dp[i-1];
		if(val[i]==val[i-1]) continue;
		if(pre[val[i]]) dp[i]=add(dp[i],dp[pre[val[i]]]);
		pre[val[i]]=i;
	}
	print(dp[n]);
	return 0;
}