#include <bits/stdc++.h>
using namespace std;
int i,j,k,n,m,x,y,t,f[310][310][310],ans;
char s[310];
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%d",&m);
	for (j=1;j<=n;j++)
		for (i=1;i<=n-j+1;i++)
			for (k=0;k<=m;k++)
				if (j==1)f[i][i][k]=1;
				else if (j==2)f[i][i+1][k]=(k||s[i]==s[i+1])?2:1;
				else{
					f[i][i+j-1][k]=max(f[i+1][i+j-1][k],f[i][i+j-2][k]);
					if (s[i]==s[i+j-1])f[i][i+j-1][k]=max(f[i][i+j-1][k],f[i+1][i+j-2][k]+2);
					else if (k)f[i][i+j-1][k]=max(f[i][i+j-1][k],f[i+1][i+j-2][k-1]+2);
				}
	for (i=0;i<=m;i++)ans=max(ans,f[1][n][i]);
	printf("%d\n",ans);
	return 0;
}