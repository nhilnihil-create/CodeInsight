#include <bits/stdc++.h>
#define int long long int
using namespace std;

//Author: Ashish

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	vector<vector<int>> comp(n,vector<int>(n));
	for(auto&itr:comp)
		for(auto&iitr:itr)
			cin>>iitr;
	const int mod=1e9+7;
	vector<vector<int>> dp(n,vector<int>(1<<n,-1));
	function<int(int,int)> dpfunction = [&](int index,int mask) {
		if(index==n) return 1LL;
		if(dp[index][mask]!=-1) return dp[index][mask];
		int ways=0;
		for(int i=0;i<n;i++)
			if(comp[index][i]==1 && ((mask&(1<<i))==0))
				ways=(ways+dpfunction(index+1,mask|(1<<i)))%mod;
		return dp[index][mask]=ways;
	};
	cout<<dpfunction(0,0);
	
	return 0;
}