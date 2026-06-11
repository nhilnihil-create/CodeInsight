#include<iostream>
#include<cstdio>
#include<cstring>

inline void check_max(int a,int &b){if(a>b)b=a;}

const int N=310,INF=1000000007;

int f[N][N][N];

char s[N];
int n,k;

int main()
{
	scanf("%s",s+1);
	scanf("%d",&k);
	n=strlen(s+1);

	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			for(int l=0;l<N;l++)
				f[i][j][l]=-INF;

	f[0][n+1][0]=0;
	
	for(int len=n+1;len>0;len--)
		for(int i=0;i+len<=n+1;i++)
		{
			int j=i+len;
			for(int l=0;l<=k;l++)
			{
				int v=f[i][j][l];
				if(v<0)continue;
				
				if(s[i+1]==s[j-1])
					check_max(v+1,f[i+1][j-1][l]);
				
				check_max(v,f[i+1][j][l]);
				check_max(v,f[i][j-1][l]);

				check_max(v+1,f[i+1][j-1][l+1]);
			}
		}

	int ans=0;

	for(int i=1;i<=n;i++)
		for(int l=0;l<=k;l++)
			check_max(f[i][i][l]*2-1,ans);
	for(int i=1;i<n;i++)
		for(int l=0;l<=k;l++)
			check_max(f[i][i+1][l]*2,ans);

	printf("%d\n",ans);

	return 0;
}
