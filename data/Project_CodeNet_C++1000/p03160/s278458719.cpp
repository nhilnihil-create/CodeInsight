#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	vector<int> v(n+1);
	for(int i=0;i<n;++i){
		cin>>v[i];
	}
	vector<int> dp(n+1,INT_MAX);
	dp[0]=0;
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n && j<=i+2;++j){
			dp[j]=min(dp[j],abs(v[j]-v[i])+dp[i]);
		}
	}
	cout<<dp[n-1];
	return 0;
}
