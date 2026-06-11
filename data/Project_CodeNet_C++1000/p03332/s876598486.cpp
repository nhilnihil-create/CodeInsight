#include<bits/stdc++.h>
#include<cmath>
using namespace std;
#define ll long long
#define rg register
#define inf 0x7f7f7f7f7f7f7f
#define maxn 521255
#define int ll
#define mod 998244353
#define pi 3.14159265358979323846264
#define x1 asdsa
#define x2 eajifedf
#define x3 jifefi
#define x4 asdij
#define x5 dskfj
#define y1 sid
#define y2 asdas
#define y3 asdoj
#define y4 xzy
#define y5 nb
#define IT set<node>::iterator
#pragma GCC optimize(3)
#pragma -fcrossjumping
#pragma -fdefer-pop
#pragma -fmerge-constans
#pragma -fthread-jumps
#pragma -floop-optimize
#pragma -fif-conversion
#pragma -fif-conversion2
#pragma -fdelayed-branch
#pragma -fguess-branch-probability
#pragma -fcprop-registers
#pragma -fforce-mem
#pragma -foptimize-sibling-calls
#pragma -fstrength-reduce
#pragma -fgcse
#pragma -fcse-follow-jumps
#pragma -frerun-cse-after-loop
#pragma -fdelete-null-pointer-checks
#pragma -fextensive-optimizations
#pragma -fregmove
#pragma -fschedule-insns
#pragma -fsched-interblock
#pragma -fcaller-saves
#pragma -fpeephole2
#pragma -freorder-blocks
#pragma -fstrict-aliasing
#pragma -funit-at-a-time
#pragma -falign-functions
#pragma -fcrossjumping
#pragma -finline-functions
#pragma -fweb
inline ll read()
{
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c<='9'&&c>='0')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x*f;
}
inline void print(ll x)
{
	if(x>=10)
	{
		print(x/10);
	}
	putchar(x%10+'0');
}
inline ll max(ll a,ll b)
{
	if(a>b) return a;
	return b;
}
inline ll min(ll a,ll b)
{
	if(a>b) return b;
	return a;
}
int jc[maxn];
int n,k,a,b,ans;
inline int ksm(int a,int b)
{
	int ans=1;
	a%=mod;
	while(b)
	{
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans%mod;
}
inline void pre_work()
{
	int sum=1;
	jc[0]=1;
	for(rg int i=1;i<=n+10;++i)
	{
		sum*=i;
		sum%=mod;
		jc[i]=sum;
	}
}
inline int C(int n,int m)
{
	if(m>n) swap(n,m);
	int ny=ksm((jc[m]*jc[n-m])%mod,mod-2);
	return jc[n]%mod*ny%mod;
}
signed main()
{
	n=read(),a=read(),b=read(),k=read();
	pre_work();
	for(rg int i=0;i<=n;++i)
	{
		if(a*i>k) break;
		int res=k-a*i;
		if(res%b!=0) continue;
		else
		{
			int numb=res/b;//b的数量 
			if(numb>n) continue;
			ans+=(C(n,i)*C(n,numb)%mod);
			ans%=mod;
		}
	}
	cout<<ans%mod;
} 