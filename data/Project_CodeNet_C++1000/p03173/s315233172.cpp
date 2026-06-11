#include <iostream>
#include <vector>
#define ll long long
#define INT_MAX 1e18
using namespace std;

ll getMinCost(vector<ll> slimes,int n) {
	ll res=0;
	vector<vector<ll>> dp(n,vector<ll>(n,0));
	vector<ll> runningSum(n+1,0);
	for(int i=0;i<n;i++) {
		dp[i][i]=slimes[i];
		runningSum[i+1]=runningSum[i]+slimes[i];
	}
	for(int size=1;size<n;size++) {
		for(int i=0;i<n-size;i++) {
			ll minCost=INT_MAX;
			//cout<<"at row "<<i<<endl;
			for(int j=0;j<size;j++) {
				ll tot=0;
				if(i+j!=i) {
					tot+=dp[i][i+j];
					//cout<<dp[i][i+j]<<" + ";
				}
				if(i+j+1!=i+size) {
					tot+=dp[i+j+1][i+size];
					//cout<<dp[i+j+1][i+size]<<" + ";
				}
				tot+=(runningSum[i+j+1]-runningSum[i])+(runningSum[i+size+1]-runningSum[i+j+1]);
				//cout<<(runningSum[i+j+1]-runningSum[i])<<" + "<<(runningSum[i+size+1]-runningSum[i+j+1])<<endl;
				if(tot<minCost) {
					minCost=tot;
				}
			}
			dp[i][i+size]=minCost;
		}
	}
	/*
	for(vector<ll> row:dp) {
		for(ll val:row) {
			cout<<val<<" ";
		}
		cout<<endl;
	}
	*/
	res=dp[0][n-1];
	return res;
}

int main() {
	int n=0;
	cin>>n;
	vector<ll> slimes(n,0);
	for(int i=0;i<n;i++) cin>>slimes[i];
	cout<<getMinCost(slimes,n)<<endl;
	return 0;
}