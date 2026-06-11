#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cassert>
#include<queue>
#include<iostream>
#include<climits>
#define Rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define Repe(i,a,b) for(register int i=(a);i>=(b);--i)
#define rep(i,a,b) for(register int i=(a);i<(b);++i)
#define pb push_back
#define mp make_pair
#define mx(a,b) (a>b?a:b)
#define mn(a,b) (a<b?a:b)
typedef unsigned long long uint64;
typedef unsigned int uint32;
typedef long long ll;
using namespace std;

namespace IO
{
    const uint32 Buffsize=1<<15,Output=1<<24;
    static char Ch[Buffsize],*S=Ch,*T=Ch;
    inline char getc()
    {
        return((S==T)&&(T=(S=Ch)+fread(Ch,1,Buffsize,stdin),S==T)?0:*S++);
    }
    static char Out[Output],*nowps=Out;
    
    inline void flush(){fwrite(Out,1,nowps-Out,stdout);nowps=Out;}

    template<typename T>inline void read(T&x)
    {
        x=0;static char ch;T f=1;
        for(ch=getc();!isdigit(ch);ch=getc())if(ch=='-')f=-1;
        for(;isdigit(ch);ch=getc())x=x*10+(ch^48);
        x*=f;
    }

    template<typename T>inline void write(T x,char ch='\n')
    {
        if(!x)*nowps++='0';
        if(x<0)*nowps++='-',x=-x;
        static uint32 sta[111],tp;
        for(tp=0;x;x/=10)sta[++tp]=x%10;
        for(;tp;*nowps++=sta[tp--]^48);
        *nowps++=ch;
        if(nowps-Out>=1<<23)flush();
    }

    inline void getstr(char*q)
	{
		register char ch;
		for(ch=getc();!isupper(ch);ch=getc());
		for(;isupper(ch);ch=getc())*q++=ch;
		*q='\0';
	}

	inline void getwd(char&x){for(x=getc();!isupper(x);x=getc());}
}
using namespace IO;

void file()
{
#ifndef ONLINE_JUDGE
    FILE*DSD=freopen("water.in","r",stdin);
    FILE*CSC=freopen("water.out","w",stdout);
#endif
}

inline void Chkmin(int&u,int v){u>v?u=v:0;}

inline void Chkmax(int&u,int v){u<v?u=v:0;}

inline void Chkmax(ll&u,ll v){u<v?u=v:0;}

inline void Chkmin(ll&u,ll v){u>v?u=v:0;}

const int MAXN=2e5+7;

static int n,Q;

static char s[MAXN];

static struct opt{char bl,dr;}q[MAXN];

inline void init()
{
	read(n),read(Q);
	getstr(s+1);
	Rep(i,1,Q)getwd(q[i].bl),getwd(q[i].dr);
}

static int ans;

inline int getps(int cr)
{
	Rep(i,1,Q)if(q[i].bl==s[cr])q[i].dr=='L'?--cr:++cr;
	return cr;
}

inline void solve()
{
	ans=n;
	int l=1,r=n;
	while(l<=r)
	{
		int md=(l+r)>>1;
		if(getps(md)==0)l=md+1;
		else r=md-1;
	}
	ans-=r;
	l=r+1,r=n;
	while(l<=r)
	{
		int md=(l+r)>>1;
		if(getps(md)==n+1)r=md-1;
		else l=md+1;
	}
	ans-=n+1-l;
	cout<<ans<<endl;
}

int main()
{
    init();
    solve();
    return 0;
}