#include<bits/stdc++.h>
#define N 305
using namespace std;
char c[N];
int i,j,k,l,s,n,m,ans,f[N][N][N];
int main() {
	scanf("%s",c+1);
	n=strlen(c+1);
	scanf("%d",&m);
	for (i=1;i<=n;i++) f[i][i][0]=1;
	for (i=1;i<n;i++) {
		if (c[i]==c[i+1]) f[i][i+1][0]=2;
		else f[i][i+1][1]=2;
	}
	for (i=1;i<=n;i++) for (j=1;j+i-1<=n;j++) for (k=0;k<=m;k++) {
		int L=j-1,R=j+i;
		if (!f[L+1][R-1][k]) continue;
		if (L&&R<=n) {
			if (c[L]==c[R]) f[L][R][k]=max(f[L][R][k],f[L+1][R-1][k]+2);
			else if (k<m) f[L][R][k+1]=max(f[L][R][k+1],f[L+1][R-1][k]+2);
		}
		f[L+1][R][k]=max(f[L+1][R][k],f[L+1][R-1][k]);
		f[L][R-1][k]=max(f[L][R-1][k],f[L+1][R-1][k]);
	}
	for (i=0;i<=n;i++) for (j=1;j<=n+1;j++) for (k=0;k<=m;k++) ans=max(ans,f[i][j][k]);
	printf("%d\n",ans);
}