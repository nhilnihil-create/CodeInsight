#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

/* // approach 1 - O(N*H)
ll getMaxBeauty(vector<int> heights, vector<ll> beauties, int n) {
	ll res=0;
	int maxHeight = *max_element(heights.begin(),heights.end());
	vector<ll> dp(n+1,0);
	for(int i=1;i<=maxHeight;i++) {
		for(int j=1;j<=n;j++) {
			if(heights[j-1]<=i && heights[j-1]>i-1) {
				dp[j]=max({dp[j],dp[j-1],dp[j-1]+beauties[j-1]});
			} else {
				dp[j]=max(dp[j],dp[j-1]);
			}
			//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}
	res=dp[n];
	return res;
}
*/

/*
//approach 2 - O(N^2)
ll getMaxBeauty(vector<int> heights, vector<ll> beauties, int n) {
	ll res=0;
	vector<int> sortedHeights=heights;
	sort(sortedHeights.begin(),sortedHeights.end());
	vector<ll> dp(n+1,0);
	for(int i:sortedHeights) {
		for(int j=1;j<=n;j++) {
			if(heights[j-1]<=i && heights[j-1]>i-1) {
				dp[j]=max({dp[j],dp[j-1],dp[j-1]+beauties[j-1]});
			} else {
				dp[j]=max(dp[j],dp[j-1]);
			}
		}
	}
	res=dp[n];
	return res;
}
*/

ll getMaxBeauty(vector<int> heights,vector<ll> beauties,int n) {
	ll res=0;
	int base=1;
	while(base<=n)base<<=2;
	vector<ll> sgmntTree(base*2,0);
	vector<ll> dp(n+1,0);
	for(int i=0;i<n;i++) {
		int x=heights[i]+base;
		ll best=0;
		while(x>1) {
			if(x%2==1) {
				best=max(best,sgmntTree[x-1]);
			}
			x>>=1;
		}
		dp[heights[i]]=best+beauties[i];
		for(int j=base+heights[i];j>0;j>>=1) {
			sgmntTree[j]=max(sgmntTree[j],dp[heights[i]]);
		}
	}
	for(int i=0;i<=n;i++) res=max(res,dp[i]);
	return res;
}

int main() {
	int n=0;
	cin>>n;
	vector<int> heights(n,0);
	vector<ll> beauties(n,0);
	for(int i=0;i<n;i++) cin>>heights[i];
	for(int i=0;i<n;i++) cin>>beauties[i];
	cout<<getMaxBeauty(heights,beauties,n)<<endl;
	return 0;
}