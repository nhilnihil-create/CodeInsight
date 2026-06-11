#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef unsigned long long ulint;
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

const int _ = 39;
const ulint bas = 1145141;

#define pick(a,b) (((a)>>(b))&1)

int n,nn;
unordered_map<ulint,int> cnt;
char s[_];

int main()
{
	n=ty(),nn=1<<n,ts(s);
	for(int i=0;i<nn;i++)
	{
		ulint a=0,b=0;
		for(int j=n-1;j>=0;j--)(pick(i,j))?(a=a*bas+s[n+j]):(b=b*bas+s[n+j]);
		for(int j=1;j<=n;j++)a=a*bas;
		a+=b,cnt[a]++;
	}
	lint ans=0;
	for(int i=0;i<nn;i++)
	{
		ulint a=0,b=0;
		for(int j=0;j<n;j++)(pick(i,j))?(a=a*bas+s[j]):(b=b*bas+s[j]);
		for(int j=1;j<=n;j++)a=a*bas;
		a+=b,ans+=cnt[a];
	}
	printf("%lld\n",ans);
	
	return 0;
}
