#include<bits/stdc++.h>
#define rg register
#define oo 0x7fffffff
#define ll long long 
#define ull unsigned ll
using namespace std;
inline int read()
{
	int out=0,fh=1;
	char jp=getchar();
	while ((jp>'9'||jp<'0')&&jp!='-')
		jp=getchar();
	if (jp=='-')
		{
			fh=-1;
			jp=getchar();
		}
	while (jp>='0'&&jp<='9')
		{
			out=out*10+jp-'0';
			jp=getchar();
		}
	return out*fh;
}
const int MAXN=2e5+10;
int n,X;
int x[MAXN];
ull pre[MAXN];
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),X=read();
	ull ans=0;
	for(rg int i=1;i<=n;++i)
		{
			x[i]=read();
			pre[i]=pre[i-1]+1ll*x[i];
		}
	ans=1ll*X*n+5*pre[n];
	for(rg int i=1;i<n;++i)
		{
			ull res=1ll*X*i;
			if(2*i>=n)
				res=res+pre[n]*5;
			else
				{
					ull coef=7;
					int lst=n-2*i;
					res+=(pre[n]-pre[lst])*5;
					while(lst>=i)
						{
							res+=(pre[lst]-pre[lst-i])*coef;
							lst-=i;
							coef+=2;
						}
					res+=pre[lst]*coef;
				}
			ans=min(ans,res);
		}
	cout<<ans+1ll*X*n;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
