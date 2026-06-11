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

static int n,H,W;

static struct node
{
	int x,y;
	friend bool operator<(node a,node b){return a.x^b.x?a.x<b.x:a.y<b.y;}
}p[MAXN];

static unordered_set<int>G[MAXN];

inline void init()
{
	read(H),read(W),read(n);
	Rep(i,1,n)read(p[i].x),read(p[i].y),G[p[i].x].insert(p[i].y);
	sort(p+1,p+n+1);
}

static int ans;

inline void Chkmax(int&u,int v){u<v?u=v:0;}

static int nps,npx;

inline void solve()
{
	nps=npx=1;
	Rep(i,1,n)
	{
		while(npx<p[i].x-1)
		{
			++npx;
			if(G[npx].find(nps+1)==G[npx].end())++nps;
		}
		if(p[i].y<=nps)cout<<p[i].x-1<<endl,exit(0);
	}
	cout<<H<<endl;
}

int main()
{
    init();
    solve();
    return 0;
}