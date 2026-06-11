#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=2e5+1e3+7;

char s[N];

int n,f[(1<<26)],g[N];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
		g[i]=g[i-1]^(1<<(s[i]-'a')); 
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=n;i++)
	{
//		f[g[i]]=f[g[i]]+1;
		for(int j=0;j<26;j++)
			f[g[i]]=min(f[g[i]],f[g[i]^(1<<j)]+1);
	}
	cout<<max(f[g[n]],1);
}