#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=305;

typedef long long LL;

int n,f[N][N][N],m,ans,la[N][26];

char S[N];

int main()
{
	scanf("%s%d",S+1,&m);
	n=strlen(S+1);
	for (int i=1;i<=n;i++)
	{
		S[i]-='a';
		for (int j=0;j<26;j++) la[i][j]=(S[i]==j)?i:la[i-1][j];
	}
	f[0][0][0]=n+1;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<=min(i,m);j++)
		{
			for (int k=0;k<=i;k++) if (f[i][j][k]>i)
			{
				ans=max(ans,k*2);
				if (f[i][j][k]-1>i) ans=max(ans,k*2+1);
				f[i+1][j][k]=max(f[i+1][j][k],f[i][j][k]);
				f[i+1][j][k+1]=max(f[i+1][j][k+1],la[f[i][j][k]-1][S[i+1]]);
				if (j<m) f[i+1][j+1][k+1]=max(f[i+1][j+1][k+1],f[i][j][k]-1);
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}