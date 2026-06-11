#include<bits/stdc++.h>
using namespace std;

const char lf = '\n';

namespace ae86
{
	const int bufl = 1<<19;

	char buf[bufl],*s=buf,*t=buf;

	inline int fetch()
	{
		if(s==t){t=(s=buf)+fread(buf,1,bufl,stdin);if(s==t)return EOF;}
		return *s++;
	}

	inline int ty()
	{
		int a=0,c=fetch();
		while(!isdigit(c))c=fetch();
		while(isdigit(c))a=a*10+c-48,c=fetch();
		return a;
	}
}
using ae86::ty;

const int _ = 200003;

int n,loc[_]={0},f[_]={0};

int main()
{
	n=ty();
	for(int i=1;i<=n;i++)loc[ty()]=i;
	int ans=0;
	for(int i=1;i<=n;i++)f[i]=((loc[i]>loc[i-1])?f[i-1]:0)+1,ans=max(ans,f[i]);
	printf("%d\n",n-ans);
	
	return 0;
}
