#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n,m,i,j,k,l,r;
int f[305][305][305];
char s[100005];

int main()
{
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%d",&m);
	for(i=1;i<=n;++i)
	for(j=0;j<=m;++j)
	f[i][i][j]=1;
	for(i=1;i<n;++i)
	for(l=1;l+i<=n;++l)
	{
		r=l+i;
		for(j=0;j<=m;++j)
		{
			f[l][r][j]=max(f[l+1][r][j],f[l][r-1][j]);
			if(s[l]==s[r])f[l][r][j]=max(f[l][r][j],f[l+1][r-1][j]+2);
			else if(j)f[l][r][j]=max(f[l][r][j],f[l+1][r-1][j-1]+2);
		}
	}
	printf("%d\n",f[1][n][m]);
}