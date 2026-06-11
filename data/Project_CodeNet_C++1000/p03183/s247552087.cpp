//by (111110101)2
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>
using namespace std;
struct st
{
	long long w,s,v;
};
st a[1010];
long long n,ans,dp[10101010];
bool cmp(st a,st b)
{
	return (a.w+a.s)<(b.w+b.s);
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].w>>a[i].s>>a[i].v;
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
	{
		for(int j=a[i].s;j>=0;j--)
		{
			dp[j+a[i].w]=max(dp[j+a[i].w],dp[j]+a[i].v);
		}
	}
	for(int i=0;i<10101000;i++)
	{
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
	return 0;
}