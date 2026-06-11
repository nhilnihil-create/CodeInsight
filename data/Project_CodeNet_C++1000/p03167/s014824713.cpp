#include <bits/stdc++.h>
using namespace  std;
const int N=1e3+10,mod=1000000007;
char g[N][N];
int f[N][N];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	getchar();
	for(int i=1;i<=n;i++)scanf("%s",g[i]+1);
	for(int i=1;i<=n;i++)
	{
		//for(int j=1;j<=m;j++)printf("%c",g[i][j]);
		//puts("");
	}
	f[1][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{

			if(i>1)
			{
				if(g[i-1][j]!='#')f[i][j]=(f[i][j]+f[i-1][j])%mod;
			}
			if(j>1)
			{
				if(g[i][j-1]!='#')f[i][j]=(f[i][j]+f[i][j-1])%mod;
			}
			if(g[i][j]=='#')f[i][j]=0;
			//printf("%d ",f[i][j]);
		}
		//puts("");

	}
	printf("%d\n",f[n][m]);
	return 0;

}