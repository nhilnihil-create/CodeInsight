#include<bits/stdc++.h>
using namespace std;
const int N=310;
int n,k,f[N][N][N];
char s[N];
int main(){
	scanf("%s",s+1);
	scanf("%d",&k);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++) f[i][i][j]=1;
	int l,r;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
			for(int x=0;x<=k;x++){
				l=j,r=j+i-1;
				f[l][r][x]=max(f[l+1][r][x],f[l][r-1][x]);
				if(x) f[l][r][x]=max(f[l][r][x],f[l+1][r-1][x-1]+2);
				if(s[l]==s[r]) f[l][r][x]=max(f[l][r][x],f[l+1][r-1][x]+2);
			}
	printf("%d",f[1][n][k]);
	return 0;
}