#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pa pair<int,int>
const int Maxn=(1<<18)+10;
const int inf=2147483647;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*f;
}
int n,a[Maxn];
int f[Maxn],g[Maxn];
int main()
{
//	freopen("subtask_1_17.txt","r",stdin);
//	freopen("1.txt","w",stdout);
	n=read();
	for(int i=0;i<(1<<n);i++)f[i]=i,a[i]=read();
	g[0]=-1;
	for(int S=1;S<(1<<n);S++)
	{
		g[S]=-1;
		for(int i=0;i<n;i++)
		if((1<<i)&S)
		{
			int t=f[S^(1<<i)];
			if(a[t]>a[f[S]])g[S]=f[S],f[S]=t;
			else if(t!=f[S]&&a[t]>a[g[S]])g[S]=t;
			t=g[S^(1<<i)];
			if(t!=-1&&a[t]>a[g[S]])g[S]=t;
		}
	}
	int ans=0;
	for(int S=1;S<(1<<n);S++)
	{
		ans=max(ans,a[f[S]]+a[g[S]]);
		printf("%d\n",ans);
	}
}