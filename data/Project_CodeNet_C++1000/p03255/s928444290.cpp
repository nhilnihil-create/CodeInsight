#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef unsigned long long ulint;
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

	inline lint ty()
	{
		lint a=0;int b=1,c=fetch();
		while(!isdigit(c))b^=c=='-',c=fetch();
		while(isdigit(c))a=a*10+c-48,c=fetch();
		return b?a:-a;
	}
}
using ae86::ty;

const int _ = 200007;

int n;
ulint per,val[_],sval[_]={0};

int main()
{
	n=ty(),per=ty();
	for(int i=1;i<=n;i++)val[i]=ty();
	sort(val+1,val+n+1);
	for(int i=1;i<=n;i++)sval[i]=sval[i-1]+val[i];

	ulint ans=per*n+sval[n]*5;

	for(int i=1;i<=n;i++)
	{
		ulint sum=per*i;
		if(i+i>=n)sum+=sval[n]*5;
		else
		{
			int las=n-i-i;
			sum+=(sval[n]-sval[las])*5;
			ulint dlt=7;
			while(las>=i)sum+=(sval[las]-sval[las-i])*dlt,dlt+=2,las-=i;
			sum+=sval[las]*dlt;
		}
		ans=min(ans,sum);
	}

	printf("%lld\n",ans+per*n);

	return 0;
}