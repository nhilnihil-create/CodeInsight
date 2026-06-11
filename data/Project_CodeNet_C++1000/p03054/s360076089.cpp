#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef long double louble;

template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}
template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}

namespace ae86
{
	const int bufl = 1<<15;
	
	char buf[bufl],*s=buf,*t=buf;
	
	inline int fetch()
	{
		if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}
		return *s++;
	}
	
	inline int ty()
	{
		int a=0,b=1,c=fetch();
		while(!isdigit(c))b^=c=='-',c=fetch();
		while(isdigit(c))a=a*10+c-48,c=fetch();
		return b?a:-a;
	}

	inline int ts(char *s)
	{
		int a=0,c=fetch();
		while(c<=32 && c!=EOF)c=fetch();
		while(c>32 && c!=EOF)s[a++]=c,c=fetch();
		s[a]=0;
		return a;
	}
}
using ae86::ty;
using ae86::ts;

const int _ = 200007;

int H,W,n,sx,sy;char s[_],t[_];

int main()
{
	H=ty(),W=ty(),n=ty();
	sy=ty(),sx=ty();
	ts(s+1),ts(t+1);

	int xl=1,xr=W,yl=1,yr=H;
	for(int i=n;i>=1;i--)
	{
		int a=s[i],b=t[i];
		xl=max(xl-(b=='R'),1)+(a=='L');
		xr=min(xr+(b=='L'),W)-(a=='R');
		yl=max(yl-(b=='D'),1)+(a=='U');
		yr=min(yr+(b=='U'),H)-(a=='D');
		if(xl>xr || yl>yr){puts("NO");return 0;}
	}
	puts((xl<=sx && sx<=xr && yl<=sy && sy<=yr)?"YES":"NO");
	
	return 0;
}
