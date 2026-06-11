#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	cin>>n>>k;
	vector<int> vec(n);
	vector<int> dp(n,0);
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		vec[i]=temp;
	}
	for(int i=0;i<k;i++){
		dp[i]=abs(vec[i]-vec[0]);
	}
	for(int i=k;i<n;i++){
		int minCost=INT_MAX;
		for(int j=1;j<=k;j++){
			minCost=min(minCost,dp[i-j]+abs(vec[i]-vec[i-j]));
		}
		dp[i]=minCost;
	}
	cout<<dp[n-1];
	return 0;
	
}
