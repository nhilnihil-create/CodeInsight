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
}
using ae86::ty;

const int _ = 200007 , __ = _<<1;

int to[__],ne[__],he[_]={0},ecnt=1;
inline void adde(int a,int b){to[++ecnt]=b,ne[ecnt]=he[a],he[a]=ecnt;}
inline void addde(int a,int b){adde(a,b),adde(b,a);}

int n,fa[_]={0},dep[_]={0},mxdep;

void dfs(int x,int ff)
{
	fa[x]=ff,dep[x]=dep[ff]+1;
	if(dep[x]>dep[mxdep])mxdep=x;
	for(int i=he[x];i;i=ne[i])if(to[i]!=ff)dfs(to[i],x);
}

int main()
{
	n=ty();
	for(int i=1,a,b;i<n;i++)a=ty(),b=ty(),addde(a,b);
	
	mxdep=1,dfs(1,0),dfs(mxdep,0);
	puts(dep[mxdep]%3==2?"Second":"First");

	return 0;
}
