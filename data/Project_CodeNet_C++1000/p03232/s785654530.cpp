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
}
using ae86::ty;

const int _ = 100007 , mo = 1000000007;

inline lint powa(lint a,lint t)
{
	lint b=1;
	while(t){if(t&1)b=b*a%mo;a=a*a%mo,t>>=1;}
	return b;
}

inline lint inva(lint a)
{
	return powa(a,mo-2);
}

int n;
lint val[_],sinv[_];

int main()
{
	n=ty();
	for(int i=1;i<=n;i++)val[i]=ty();
	sinv[0]=0;
	for(int i=1;i<=n;i++)sinv[i]=(sinv[i-1]+inva(i))%mo;

	lint ans=0;
	for(int i=1;i<=n;i++)
		ans=(ans+(sinv[i]+sinv[n-i+1]-sinv[1]+mo)%mo*val[i]%mo)%mo;
	for(int i=1;i<=n;i++)ans=ans*i%mo;
	printf("%lld\n",ans);

	return 0;
}
