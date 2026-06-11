#include<iostream>
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int h[200005];
int a[200005];
int dp[200005];
int solve()
{
//We basically need to find the increading height subsequence with maximum beauty 
//Ending at i
//This is standard technique for any subsequence problem.

	map<int,int> mp;
	dp[0] = 0;
	dp[1] = a[1];
	mp[h[1]] = dp[1];
	int ans=dp[1];

	for(int i=2;i<=n;i++)
	{
		dp[i] = a[i];
		auto it = mp.lower_bound(h[i]+1);
		if(it!=mp.begin()){
			it--;
			dp[i]+=(it->second);
		}
		mp[h[i]] = dp[i];
		it = mp.upper_bound(h[i]);
		while(it!=mp.end() && it->second <= dp[i])
		{
			auto temp = it;
			temp++;
			mp.erase(it);
			it=temp;
		}


		ans = max(ans,dp[i]);

	}

return ans;
}
int32_t main(){
#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	for(int i=1;i<=n;i++)
		cin>>a[i];
	memset(dp,0,sizeof dp);

	cout<<solve()<<endl;










}