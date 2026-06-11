#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
char s[310];
int K,n,f[310][310][310];
int read()
{
	int x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
int main()
{
	scanf("%s%d",s+1,&K);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		for(int k=0;k<=K;k++)
			f[i][i][k]=1;
	for(int len=1;len<n;len++)
		for(int l=1,r=len+1;r<=n;r++,l++)
			for(int k=0;k<=K;k++)
			{
				f[l][r][k]=max(f[l+1][r][k],f[l][r-1][k]);
				if(s[l]==s[r]) f[l][r][k]=max(f[l+1][r-1][k]+2,f[l][r][k]);
				else if(k) f[l][r][k]=max(f[l+1][r-1][k-1]+2,f[l][r][k]);
			}
	printf("%d",f[1][n][K]);		
    return 0;
}

