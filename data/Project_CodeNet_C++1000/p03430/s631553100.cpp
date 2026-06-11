#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 300
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char st[MN+5];
int f[MN/2+5][MN/2+5][MN/2+5],g[MN/2+5][MN/2+5][MN/2+5],n,K,ans=0;
inline void R(int&x,int y){y>x?x=y:0;}
void Solve()
{
	memset(f,200,sizeof(f));f[0][0][0]=0;
	for(int k=0;k<=K;++k)
		for(int i=0;i<=n>>1;++i)
			for(int j=0;j<=n>>1;++j) if(f[k][i][j]>=0)
			{
				R(f[k+1][i][j],f[k][i][j]);
				R(f[k][i+1][j],f[k][i][j]);
				R(f[k][i][j+1],f[k][i][j]);
				if(i<n>>1&&j<n>>1&&st[i+1]==st[n-j]) R(f[k][i+1][j+1],f[k][i][j]+1);
				else R(f[k+1][i+1][j+1],f[k][i][j]+1);
			}
	memset(g,200,sizeof(g));
	for(int i=1;i<=n+1>>1;++i) for(int j=0;j<=K;++j) g[j][i][i]=1,g[j][i+1][i]=0;
	for(int k=0;k<=K;++k)
		for(int i=n+1>>1;i;--i)
			for(int j=i;j<=n+1>>1;++j)
			{
				R(g[k][i][j],g[k][i][j-1]);
				R(g[k][i][j],g[k][i+1][j]);
				if(k) R(g[k][i][j],g[k-1][i][j]),R(g[k][i][j],g[k-1][i+1][j-1]+2);
				if(st[i]==st[j]) R(g[k][i][j],g[k][i+1][j-1]+2);
				//cout<<k<<" "<<i<<" "<<j<<" "<<st[i]<<" "<<st[j]<<" "<<g[k][i][j]<<endl;
			}
	for(int i=0;i<=n>>1;++i) for(int j=0;j<=K;++j)
		ans=max(ans,f[j][i][n>>1]*2+(i<n+1>>1?g[K-j][i+1][n+1>>1]:0));
	if(n&1) ans=max(ans,2*f[K][n>>1][n>>1]+1);
}
int main()
{
	scanf("%s",st+1);n=strlen(st+1);K=read();
	if(K>n>>1) return 0*printf("%d\n",n);
	Solve();
	for(int l=1,r=n;l<r;++l,--r) swap(st[l],st[r]);
	Solve();
	printf("%d\n",ans);
	return 0;
}

