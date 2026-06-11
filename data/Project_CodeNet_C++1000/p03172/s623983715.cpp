#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll getNumberOfWays(vector<int> limits,int n,int k) {
	ll out=0;
	vector<ll> dp(k+1,0);
	dp[0]=1;
	for(int children=1;children<=n;children++) {
		vector<ll> stepSum(k+2,0);
		for(int iter=k;iter>=0;iter--) {
			if(iter+1<=min(iter+limits[children-1],k)) {
				stepSum[iter+1]+=dp[iter];
				stepSum[iter+1]%=(ll)1e9+7;
				stepSum[min(iter+limits[children-1],k)+1]-=dp[iter];
				stepSum[min(iter+limits[children-1],k)+1]%=(ll)1e9+7;
			}
		}
		ll inc=0;
		for(int i=0;i<k+1;i++) {
			inc+=stepSum[i];
			dp[i]+=inc;
          	dp[i]%=(ll)(1e9+7);
		}
	}
	/*
	for(ll val:dp) {
		cout<<val<<" ";
	}cout<<endl;
	*/
	out=dp[k];
	return out%(ll)(1e9+7);
}

int main() {
	int n=0,k=0;
	cin>>n>>k;
	vector<int> limits(n,0);
	for(int i=0;i<n;i++)cin>>limits[i];
	cout<<getNumberOfWays(limits,n,k)<<endl;
	return 0;
}
