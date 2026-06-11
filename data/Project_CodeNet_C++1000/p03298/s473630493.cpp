#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
LL ans;
int n,f[20][20];
char s[40],a[20],b[20];
int main()
{
	re(n);
	scanf("%s",s);
	for(int i=0;i<(1<<n);++i)
	{
		int aa=0,bb=0;
		for(int j=0;j<n;++j)
			if(i>>j&1)a[++aa]=s[j];
			else b[++bb]=s[j];
/*		for(int j=1;j<=aa;++j)putchar(a[j]);
		puts("");
		for(int j=1;j<=bb;++j)putchar(b[j]);
		cerr<<aa<<" "<<bb<<endl;*/
		memset(f,0,sizeof f);
		f[0][0]=1;
		for(int j=0;j<=aa;++j)
			for(int k=0;k<=bb;++k)if(j<aa || k<bb)
			{
//				putchar(s[n+n-j-k-1]);
//				printf(" %d %d\n",j,k);
				if(s[n+n-j-k-1]==a[j+1])f[j+1][k]+=f[j][k];
				if(s[n+n-j-k-1]==b[k+1])f[j][k+1]+=f[j][k];
			}
/*		for(int j=0;j<=aa;++j,puts(""))
			for(int k=0;k<=bb;++k)
				printf("%d ",f[j][k]);*/
		ans+=f[aa][bb];
//		return 0;
	}
	printf("%lld\n",ans);
}