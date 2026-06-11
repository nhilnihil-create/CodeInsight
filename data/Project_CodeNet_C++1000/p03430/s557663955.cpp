#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
const int N=308;
int n,m,ans,a[N][N][N];
char b[N];
int maxx(int x,int y){if(x>y)y=x;return y;}
int main(void)
{
	int i,j,k;
	scanf("%s%d",b+1,&m);
	n=strlen(b+1);ans=1;
	for(i=1;i<=n;i++)for(j=0;j<=m;j++)a[j][i][i]=1;
	for(k=0;k<=m;k++)
	for(i=n;i>=1;i--)
	for(j=i+1;j<=n;j++)
	{
		if(k){a[k][i][j]=maxx(a[k][i][j],a[k-1][i][j]);}
		if(k){a[k][i][j]=maxx(a[k][i][j],2+a[k-1][i+1][j-1]);}
		a[k][i][j]=maxx(a[k][i][j],maxx(maxx(a[k][i+1][j],a[k][i][j-1]),(b[i]==b[j])*(2+a[k][i+1][j-1])));
	}
	cout<<a[m][1][n];
	return 0;
}