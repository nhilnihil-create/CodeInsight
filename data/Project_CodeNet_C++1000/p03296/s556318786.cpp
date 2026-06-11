#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef long double louble;

#define lf ('\n')

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

const int _ = 103;

int n,val[_];

int main()
{
	n=ty();
	for(int i=1;i<=n;i++)val[i]=ty();

	int ans=0;
	for(int l=1,r=1;l<=n;l=r+1)
	{
		r=l;while(val[r+1]==val[l])r++;
		ans+=(r-l+1)/2;
	}
	cout<<ans<<lf;

	return 0;
}
