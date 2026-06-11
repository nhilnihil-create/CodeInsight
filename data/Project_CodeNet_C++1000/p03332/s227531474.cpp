#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef long double louble;

const char lf = '\n';

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
	
	inline lint ty()
	{
		lint a=0;int b=1,c=fetch();
		while(!isdigit(c))b^=c=='-',c=fetch();
		while(isdigit(c))a=a*10+c-48,c=fetch();
		return b?a:-a;
	}
}
using ae86::ty;

const int _ = 300007 , mo = 998244353;

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

lint jc[_],rjc[_];

void fuck(int n=_-1)
{
	jc[0]=jc[1]=rjc[0]=1;
	for(int i=2;i<=n;i++)jc[i]=jc[i-1]*i%mo;
	rjc[n]=inva(jc[n]);
	for(int i=n-1;i>=1;i--)rjc[i]=rjc[i+1]*(1ll+i)%mo;
}

inline lint C(int n,int m)
{
	if(n<m || n<0 || m<0)return 0;
	return jc[n]*rjc[m]%mo*rjc[n-m]%mo;
}

lint finder(lint a,lint b,lint n)
{
	if(a>n || b>n)return 0;
	return C(n,a)*C(n,b)%mo;
}

int n;
lint a,b,tar;

int main()
{
	ios::sync_with_stdio(0),cout.tie(0);
	
	fuck();
	n=ty(),a=ty(),b=ty(),tar=ty();
	lint ans=0;
	for(int i=0;i<=n;i++)if((tar-a*i)%b==0)ans=(ans+finder(i,(tar-a*i)/b,n))%mo;
	printf("%lld\n",ans);

	return 0;
}
