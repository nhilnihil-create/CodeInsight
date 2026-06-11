#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,k;
int f[310][310][310];
char s[110];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&k);
	for (int i=1;i<=n;i++)
		for (int j=0;j<=k;j++) f[i][i][j]=1;
	for (int len=2;len<=n;len++)
		for (int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			for (int i=0;i<=k;i++)
			{
				if (i) f[l][r][i]=f[l][r][i-1];
				f[l][r][i]=max(f[l][r][i],f[l+1][r][i]);
				f[l][r][i]=max(f[l][r][i],f[l][r-1][i]);
				if (i) f[l][r][i]=max(f[l][r][i],f[l+1][r-1][i-1]+2);
				if (s[l]==s[r]) f[l][r][i]=max(f[l][r][i],f[l+1][r-1][i]+2);
			}
		}
	printf("%d",f[1][n][k]);
}