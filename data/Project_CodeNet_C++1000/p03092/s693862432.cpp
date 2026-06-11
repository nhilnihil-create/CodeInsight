#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef long double louble;

template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?b:a;}
template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?a:b;}
template<typename T1,typename T2> inline T1 gmax(T1 &a,T2 b){return a=a<b?b:a;}
template<typename T1,typename T2> inline T1 gmin(T1 &a,T2 b){return a=a<b?a:b;}

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

const int _ = 5007;

int n,val[_];
lint f[_][_],sl=0,sr=0;

int main()
{
	n=ty(),sr=ty(),sl=ty();
	for(int i=1;i<=n;i++)val[i]=ty();
	memset(f,63,sizeof(f)),f[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=val[i];j++)gmin(f[i][val[i]],f[i-1][j]),gmin(f[i][j],f[i-1][j]+sr);
		for(int j=val[i]+1;j<=n;j++)gmin(f[i][j],f[i-1][j]+sl);
	}

	lint ans=1e18;
	for(int i=0;i<=n;i++)ans=min(ans,f[n][i]);
	printf("%lld\n",ans);
	
	return 0;
}
