#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node{int w,s,v;} a[10005];
int n,dp[10000005],ans;
int cmp(node a,node b){return a.w+a.s<b.w+b.s;}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i].w>>a[i].s>>a[i].v;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		for(int j=a[i].s;j>=0;j--)
			dp[j+a[i].w]=max(dp[j+a[i].w],dp[j]+a[i].v);
	cout<<*max_element(dp,dp+10000000)<<endl;
	return 0;
}