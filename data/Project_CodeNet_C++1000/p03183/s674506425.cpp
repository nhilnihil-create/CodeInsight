#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,dp[20010];
pair<pair<int,int>,pair<int,int> > a[1010];  

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		int w,s,v;
		cin>>w>>s>>v;
		a[i]=make_pair(make_pair(w+s,w),make_pair(s,v));
	}
	sort(a+1,a+n+1); 
	for(int i=1;i<=n;i++){
		for(int j=a[i].second.first;j>=0;j--){
			dp[j+a[i].first.second]=max(dp[j+a[i].first.second],dp[j]+a[i].second.second);
		}
	}
	int maxv=0;
	for(int j=0;j<=20000;j++) maxv=max(maxv,dp[j]);
	cout<<maxv<<endl;
	return 0;
}