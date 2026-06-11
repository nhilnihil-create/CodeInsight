#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e3+5;
const int maxval=2e4+5;
int w[maxn],s[maxn],arr[maxn];
ll v[maxn];
bool Less1(int a,int b)
{
	return s[a]+w[a]<s[b]+w[b];
}
ll maxx[maxn][maxval];
void fl()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
int main()
{
//    fl();
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%lld",&w[i],&s[i],&v[i]);
		arr[i]=i;
	}
	sort(arr+1,arr+n+1,Less1);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=20000;j++)
		{
			maxx[i][j]=maxx[i-1][j];
			if(j>=w[arr[i]]&&j-w[arr[i]]<=s[arr[i]])
				maxx[i][j]=max(maxx[i][j],maxx[i-1][j-w[arr[i]]]+v[arr[i]]);
		}
	ll ans=0;
	for(int j=0;j<=20000;j++)
		ans=max(ans,maxx[n][j]);
	printf("%lld\n",ans);
	return 0;
}
