#include<iostream>
#include<iomanip>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
int read()
{
	char c=getchar();
	int res=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=(res<<1)+(res<<3)+(c^48),c=getchar();
	return res;
}
int n,A,B;
int a[5005];
long long dp[5005];
int main()
{
	n=read(),A=read(),B=read();
	for(int i=1;i<=n;i++) a[i]=read();
	a[n+1]=0x3f3f3f3f;memset(dp,0x3f,sizeof(dp));dp[0]=0;
	for(int i=1;i<=n+1;i++)
	{
		int sl=0,sr=0;
		for(int j=i-1;j>=0;j--)
		{
			if(a[j]<a[i]) dp[i]=min(dp[i],dp[j]+1ll*sl*A+1ll*sr*B);
			if(a[j]>a[i]) sl++;if(a[j]<a[i]) sr++;
		}
	}
	printf("%lld\n",dp[n+1]);
}