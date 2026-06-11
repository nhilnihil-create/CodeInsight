#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstdlib>

using namespace std;

const int MAXN=200010;
const int MAXM=(1<<26);
char s[MAXN];
int f[MAXN],g[MAXN],minn[MAXM];

int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for (int i=1;i<=n;i++)
	{
		int c=s[i]-'a';
		g[i]=g[i-1]^(1<<c);
	}
	minn[0]=0;
	for (int i=1;i<(1<<26);i++)
	{
		minn[i]=1e9;
	}
	for (int i=1;i<=n;i++)
	{
		f[i]=1e9;
		for (int j=0;j<26;j++)
		{
			int zt=g[i]^(1<<j);
			f[i]=min(f[i],minn[zt]+1);
		}
		f[i]=min(f[i],minn[g[i]]+1);
		minn[g[i]]=min(minn[g[i]],f[i]);
	}
	cout<<f[n];
	return 0;
}
