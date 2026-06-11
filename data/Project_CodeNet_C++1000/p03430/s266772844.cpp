//#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
//#include<math.h>
//#include<time.h>
//#include<complex>
#include<algorithm>
using namespace std;

int n,K;
#define maxn 311
char s[maxn];
int f[maxn][maxn][maxn];
int main()
{
	scanf("%s",s+1); n=strlen(s+1); scanf("%d",&K);
	for (int i=1;i<=n;i++)
		for (int j=0;j<=K;j++)
			f[i][i][j]=1;
	for (int len=1;len<n;len++)
		for (int i=1;i<=n-len;i++)
		{
			int j=i+len;
			for (int k=0;k<=K;k++)
			{
				f[i][j][k]=max(f[i][j][k-1],max(f[i][j-1][k],f[i+1][j][k]));
				if (s[i]==s[j]) f[i][j][k]=max(f[i][j][k],f[i+1][j-1][k]+2);
				if (s[i]!=s[j] && k) f[i][j][k]=max(f[i][j][k],f[i+1][j-1][k-1]+2);
			}
		}
	printf("%d\n",f[1][n][K]);
	return 0;
}