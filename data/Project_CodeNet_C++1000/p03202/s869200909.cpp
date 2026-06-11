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

const int _ = 200007;

int n,val[_],los[_]={0},nlos=0;
int stk[_]={0},ps[_]={0},top;

inline void push(int x)
{
	if(top && stk[top]==x)ps[top]++;
	else top++,stk[top]=x,ps[top]=1;
}

inline int able(int m)
{
	top=0;
	for(int i=1;i<=nlos;i++)
	{
		int loc=los[i];
		while(top && stk[top]>loc)top--;
		push(loc);
		while(top && stk[top]>0 && ps[top]>=m)top--,push(stk[top+1]-1);
		if(top<=0 || !stk[top])return 0;
	}
	return 1;
}

int main()
{
	n=ty();
	for(int i=1;i<=n;i++)val[i]=ty();
	for(int i=2;i<=n;i++)if(val[i]<=val[i-1])los[++nlos]=val[i];

	int l=1,r=n;
	while(r>l){int mid=(l+r)>>1;if(able(mid))r=mid;else l=mid+1;}
	printf("%d\n",r);

	return 0;
}
