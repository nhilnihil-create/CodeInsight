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
	vector<int> input(n);
	for(auto&itr:input) cin>>itr;
	vector<vector<int>> cache(n,vector<int>(n,-1));
	
	function<int(int,int)> dp = [&](int l,int r) {
		if(cache[l][r]!=-1) return cache[l][r];
		if(l==r) return cache[l][r]=0;
		int answer=1e18;
		int sum=0;
		for(int i=l;i<=r;i++) sum+=input[i];
		for(int i=l;i<r;i++) {
			answer=min(answer,dp(l,i)+dp(i+1,r)+sum);
		}
		return cache[l][r]=answer;
	};

	cout<<dp(0,n-1);
	
	return 0;
}