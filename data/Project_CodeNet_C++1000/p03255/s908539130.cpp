#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ul unsigned long long
#define inf 1e18
const int _=2e5+5;
inline int read()
{
	char ch='!';int z=1,num=0;
	while(ch!='-'&&(ch<'0'||ch>'9'))ch=getchar();
	if(ch=='-')z=-1,ch=getchar();
	while(ch<='9'&&ch>='0')num=(num<<3)+(num<<1)+ch-'0',ch=getchar();
	return z*num;
}
int n,X;
ul d[_];
int main()
{
	n=read(),X=read();
	for(int i=1;i<=n;++i)d[i]=read(),d[i]+=d[i-1];
	ul ans=inf;
	for(int k=1;k<=n;++k)
	{
		ul s=0,xi=3;
		s+=(d[n]-d[max(0,n-k)])*2;
		for(int i=n;i>=1;i-=k,xi+=2)
			s+=(d[i]-d[max(0,i-k)])*xi;
		ans=min(ans,s+1ll*(n+k)*X);
	}
	printf("%llu\n",ans);
	return 0;
}