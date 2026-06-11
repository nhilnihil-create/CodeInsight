#include<bits/stdc++.h>
using namespace std;

char s[311],s1[311],s2[311];
int k,f[311][311][311],n,ans,ma;

int main()
{
	scanf("%s%d",s,&k),n=strlen(s);
	for (int i=0; i<n; i++) s1[i+1]=s[i],s2[i+1]=s[n-i-1];
	for (int i=0; i<=n; i++) 
		for (int j=0; j<=n; j++)
			for (int l=0; l<=k; l++) f[i][j][l]=-114514;
	for (int i=0; i<=n; i++) 
		for (int j=0; j<=k; j++) f[0][i][j]=f[i][0][j]=0;
	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			for (int l=0; l<=k; l++)
			{
				f[i][j][l]=max(f[i-1][j-1][l]+(s1[i]==s2[j]),max(f[i-1][j][l],f[i][j-1][l]));
				if (l) f[i][j][l]=max(f[i][j][l],f[i-1][j-1][l-1]+1);
			}
	ans=1;
	for (int i=0; i<n; i++) ans=max(ans,max(2*f[i][n-i][k],2*f[i][n-i-1][k]+1));
	return printf("%d\n",ans),0;
}