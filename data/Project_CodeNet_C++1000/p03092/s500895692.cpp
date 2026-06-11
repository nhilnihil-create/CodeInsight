#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define N 5005
#define ll long long
using namespace std;
int n,a,b;
int s[N];
ll f[N][N];
int main()
{
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++) scanf("%d",&s[i]);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			f[i][j]=1e15;
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(j<s[i]) f[i][s[i]]=min(f[i][s[i]],f[i-1][j]);
			if(j<s[i]) f[i][j]=min(f[i][j],f[i-1][j]+a);
			if(j>s[i]) f[i][j]=min(f[i][j],f[i-1][j]+b);
		}
	}
	ll ans=1e15;
	for(int i=1;i<=n;i++) ans=min(ans,f[n][i]);
	printf("%lld\n",ans);
	return 0;
}