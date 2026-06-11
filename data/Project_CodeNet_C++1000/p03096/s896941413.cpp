//%std
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read()
{
	int out=0,fh=1;
	char jp=getchar();
	while ((jp>'9'||jp<'0')&&jp!='-')
		jp=getchar();
	if (jp=='-')
		fh=-1,jp=getchar();
	while (jp>='0'&&jp<='9')
		out=out*10+jp-'0',jp=getchar();
	return out*fh;
}
const int P=1e9+7;
int add(int a,int b)
{
	return (a+b>=P)?(a+b-P):(a+b);
}
int mul(int a,int b)
{
	return 1LL * a * b % P;
}
const int MAXN=2e5+10;
int n,f[MAXN],lst[MAXN];
int main()
{
	n=read();
	f[0]=1;
	for(int i=1;i<=n;++i)
	{
		f[i]=f[i-1];
		int c=read();
		if(lst[c] && i-lst[c]>1)
			f[i]=add(f[i],f[lst[c]]);
		lst[c]=i;
	}
	cout<<f[n]<<endl;
	return 0;
}
