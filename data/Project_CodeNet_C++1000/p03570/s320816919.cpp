#include<iostream>
#include<cstring>
#include<cstdio>
#define N 200010
using namespace std;
int minv[(1<<26)+10],bv[N],dp[N];
bool vis[(1<<26)+10];
inline int updv(int x,int p)
{
	return x^(1<<p);
}
char s[N];
inline int getv(int x,int p)
{
	return (x&(1<<p))>>p;
}
inline int out(int x)
{
	for(int i=0;i<26;i++)
		printf("%d",getv(x,i));
	cout<<endl;return 0;
}
int main()
{
	scanf("%s",s+1);
	int n=strlen(s+1),v=0;
	for(int i=0;i<26;i++)
		bv[i]=updv(0,i);
	vis[0]=true;
	for(int i=1;i<=n;i++)
	{
		v=updv(v,s[i]-'a'),dp[i]=i;
		if(vis[v]) dp[i]=minv[v]+1;
		for(int j=0;j<26;j++)
		{
			int x=v^bv[j];
			if(vis[x]) dp[i]=min(dp[i],minv[x]+1);
		}
		if(!vis[v]) minv[v]=dp[i];
		else minv[v]=min(minv[v],dp[i]);
		vis[v]=true;
	}
	return !printf("%d\n",dp[n]);
}