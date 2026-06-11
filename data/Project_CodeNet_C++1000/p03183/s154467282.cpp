#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000+10;
const int MAXNA=20000+20;
long long n,ans;
long long dp[MAXNA];
struct p
{
	int w;
	int s;
	int v;
}A[MAXN];
bool cmp(p a,p b)
{
	return (a.w+a.s)<(b.w+b.s);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>A[i].w>>A[i].s>>A[i].v;
	}
//	cout<<"\n";
	sort(A,A+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		for(int j=A[i].s;j>=0;j--)
		{
			dp[j+A[i].w]=max(dp[j+A[i].w],dp[j]+A[i].v);
		}
	}
	for(int i=0;i<=MAXNA-1;i++)
	{
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}