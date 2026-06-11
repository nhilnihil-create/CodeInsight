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

const int _ = 200007 , mo = 1000000007;

int n,col[_],las[_]={0};
lint f[_]={0};

int main()
{
	n=ty();
	for(int i=1;i<=n;i++)col[i]=ty();

	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		if(las[col[i]] && col[i]!=col[i-1])f[i]=(f[i]+f[las[col[i]]]+1)%mo;
		las[col[i]]=i;
	}
	printf("%lld\n",(f[n]+1)%mo);

	return 0;
}
