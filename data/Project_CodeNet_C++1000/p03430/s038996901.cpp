#include <bits/stdc++.h>
#define Maxn 307
using namespace std;
char s[Maxn];
int n,k;
int f[Maxn][Maxn][Maxn];
int calc(int x,int y)
{
	if (s[x]==s[y]) return 0;
	return 1;
}
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&k);
	for (int i=1;i<=n;i++)
		for (int j=0;j<=k;j++)
			f[i][i][j]=1;
	for (int del=1;del<n;del++)
		for (int i=1;i+del<=n;i++)
		{
			int j=i+del;
			for (int r=0;r<=k;r++)
			{
				f[i][j][r]=max(f[i+1][j][r],f[i][j-1][r]);
				int t=calc(i,j);
				if (r>=t) 
				{
					if (i+1>j-1) f[i][j][r]=max(2,f[i][j][r]);
					else f[i][j][r]=max(f[i][j][r],f[i+1][j-1][r-t]+2);
				}
			}
		}
	printf("%d\n",f[1][n][k]);
	return 0;
}
