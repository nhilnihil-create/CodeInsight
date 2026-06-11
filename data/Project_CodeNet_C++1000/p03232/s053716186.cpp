#include <bits/stdc++.h>
#define N 200010
#define mod 1000000007
using namespace std;

inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
inline int qpow(int bas,int pw)
{
	int res=1; for(;pw;pw>>=1,bas=1ll*bas*bas%mod)
		if(pw&1) res=1ll*res*bas%mod; return res;
}
inline void add(int &x,int y)
{
	x+=y; if(x>=mod) x-=mod;
	if(x<0) x+=mod;
}
int n,fac[N],pre[N],sum;
inline int deal(int x)
{
	return (1ll*pre[x]+1ll*pre[n-x+1]-1ll+mod)%mod;
}
int main()
{
	fac[0]=1; for(int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mod;
	pre[0]=pre[1]=1;
	for(int i=2;i<N;i++) 
		pre[i]=(1ll*pre[i-1]+qpow(i,mod-2))%mod;
	cin >> n;
	// for(int i=1;i<=n;i++) printf("%d ",fac[i]); puts("");
	// for(int i=1;i<=n;i++) printf("%d ",pre[i]); puts("");
	for(int i=1;i<=n;i++)
	{
		int x; cin >> x;
		add(sum,1ll*x*deal(i)%mod);
	}
	cout << 1ll*sum*fac[n]%mod << endl;
	return 0;
}