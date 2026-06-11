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
	for(;k>='0'&&k<='9';k=getchar()) x=x*10+k-'0';
	x*=f;
}
template<class T>il _print(T x){
	if(x>=10) _print(x/10);
	putchar(x%10+'0');
}
template<class T>il print(T x){
	if(x<0) putchar('-'),x=-x;
	_print(x);
}
ll mul(ll a,ll b,ll mod){long double c=1.;return (a*b-(ll)(c*a*b/mod)*mod)%mod;}
it qpow(int x,int k,int mod){
	int res=1,bas=x;
	while(k){
		if(k&1) res=1ll*res*bas%mod;
		bas=1ll*bas*bas%mod,k>>=1;
	}
	return res;
}
int n,k;
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	read(n),read(k);
	if(n==1){
		if(k==0) printf("0 0 1 1");
		else printf("-1");
		return 0;
	}
	int S=(1<<n)-1;
	if(k>S) return puts("-1"),0;
	for(ri i=0;i<=S;++i) if(i^k) printf("%d ",i);
	printf("%d ",k);
	for(ri i=S;i>=0;--i) if(i^k) printf("%d ",i);
	printf("%d ",k);
	return 0;
}