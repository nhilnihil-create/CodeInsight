#include<bits/stdc++.h>
#define Rep(i,a,b) for(register int i=(a);i<=(b);++i)
#define Repe(i,a,b) for(register int i=(a);i>=(b);--i)
#define pb push_back
#define mp make_pair
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
	}
}
using namespace IO;

inline void file()
{
#ifndef ONLINE_JUDGE
	FILE*WA=freopen("water.in","r",stdin);
	FILE*TER=freopen("water.out","w",stdout);
#endif
}

const int MAXN=2e5+7;

static int n,a[MAXN];

inline void init()
{
	read(n);
	Rep(i,1,n)read(a[i]);
}

inline bool Judge(int x)
{
	static map<int,int>G;
	G.clear();
	Rep(i,2,n)if(a[i]<=a[i-1])
	{
		G.erase(G.upper_bound(a[i]),G.end());
		++G[a[i]];
		for(int k=a[i];k&&G[k]==x;--k)
			G.erase(k),++G[k-1];
		if(G.find(0)!=G.end())return 0;
	}
	return 1;
}

inline void solve()
{
	static int flg=1;
	Rep(i,2,n)if(a[i]<=a[i-1]){flg=0;break;}
	if(flg)cout<<1<<endl,exit(0);
	int l=2,r=n,md;
	while(l<=r)
	{
		md=(l+r)>>1;
		if(Judge(md))r=md-1;
		else l=md+1;
	}
	cout<<l<<endl;
}

int main()
{
    init();
    solve();
    return 0;
}