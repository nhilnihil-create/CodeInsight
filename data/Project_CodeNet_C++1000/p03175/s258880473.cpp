#include <bits/stdc++.h>
#define int long long int
using namespace std;

//Author: Ashish

//dp[i][0] -> ways when the parent of i was black
//dp[i][1] -> ways when the parent of i was white

int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;

	vector<vector<int>> graph(n,vector<int>());
	for(int i=1;i<n;i++) {
		int x,y;
		cin>>x>>y;
		--x;
		--y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	const int mod = 1e9+7;

	function<pair<int,int>(int,int)> dp = [&](int node,int parent) {
		// {black,white}
		int black=1,white=1;
		for(auto&itr:graph[node]) {
			if(itr==parent) continue;
			pair<int,int> child = dp(itr,node);
			black*=child.second;
			white*=(child.first+child.second)%mod;
			black%=mod;
			white%=mod;
		}
		return make_pair(black,white);
	};
	pair<int,int> answer=dp(0,-1);
	cout<<(answer.first+answer.second)%mod;
	return 0;
}