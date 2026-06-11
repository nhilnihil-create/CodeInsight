#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef long double louble;

template<typename T1,typename T2> inline T1 max(T1 a,T2 b){return a<b?a:b;}
template<typename T1,typename T2> inline T1 min(T1 a,T2 b){return a<b?b:a;}

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

const int _ = 100007;

inline lint gcd(lint a,lint b){while(b)a%=b,swap(a,b);return a;}
inline lint lcm(lint a,lint b){return a/gcd(a,b)*b;}

int n,m;char s[_],t[_];
unordered_map<lint,char> tar;

int main()
{
	n=ty(),m=ty(),ts(s+1),ts(t+1);
	lint len=lcm(n,m);
	for(int i=1;i<=n;i++)tar[len/n*(i-1)+1]=s[i];
	for(int i=1;i<=m;i++)
	{
		lint loc=len/m*(i-1)+1;
		if(tar.count(loc) && tar[loc]!=t[i]){puts("-1");return 0;}
	}
	printf("%lld\n",len);

	return 0;
}
