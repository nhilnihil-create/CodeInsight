#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
const int Maxn=2010;
const int inf=2147483647;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*f;
}
int n,k,q,a[Maxn],b[Maxn],c[Maxn],lc,d[Maxn],ld,ans=inf;bool mark[Maxn];
int main()
{
	n=read(),k=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=b[i]=read();
	sort(b+1,b+1+n);int m=unique(b+1,b+1+n)-b-1;
	mark[0]=mark[n+1]=true;
	for(int i=1;i<=m;i++)
	{
		int lst=0;ld=0;
		for(int j=1;j<=n+1;j++)
		if(mark[j])
		{
			if(j-lst-1>=k)
			{
				lc=0;
				for(int l=lst+1;l<j;l++)c[++lc]=a[l];
				sort(c+1,c+1+lc);
				for(int l=1;l<=lc-k+1;l++)d[++ld]=c[l];
			}
			lst=j;
		}
		if(ld<q)break;
		sort(d+1,d+1+ld);
		ans=min(ans,d[q]-d[1]);
		for(int j=1;j<=n;j++)if(a[j]==b[i])mark[j]=true;
	}
	printf("%d",ans);
}
