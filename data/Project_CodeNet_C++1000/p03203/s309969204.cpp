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

const int _ = 200007;

int n,H,W;
vector<int> los[_];

int main()
{
	H=ty(),W=ty(),n=ty();
	for(int i=1,a,b;i<=n;i++)a=ty(),b=ty(),los[a-1].emplace_back(b-1);
	for(int i=1,now=0;i<H;i++)
	{
		sort(los[i].begin(),los[i].end());
		if(los[i].empty() || los[i][0]>now+1)now++;
		else if(los[i][0]<=now){printf("%d\n",i);return 0;}
	}
	printf("%d\n",H);

	return 0;
}
