#include <bits/stdc++.h>
using namespace std;
#define N 201000

char s[N];
int n,sum[N],f[N],g[1<<26];
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for (int i=1;i<=n;i++) sum[i]=sum[i-1]^(1<<(s[i]-'a'));
	
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	g[0]=0;
	for (int i=1;i<=n;i++)
	{
		f[i]=min(f[i],g[sum[i]]+1);
		for (int j=0;j<26;j++) f[i]=min(f[i],g[sum[i]^(1<<j)]+1);
		g[sum[i]]=min(g[sum[i]],f[i]);
	}
	printf("%d\n",f[n]);
	return 0;
}