#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> vec(n);
	vector<int> dp(n,0);
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		vec[i]=temp;
	}
	dp[0]=0;
	dp[1]=abs(vec[1]-vec[0]);
	for(int i=2;i<n;i++){
		dp[i]=min(dp[i-1]+abs(vec[i]-vec[i-1]),dp[i-2]+abs(vec[i]-vec[i-2]));
	}
	cout<<dp[n-1];
	return 0;
	
}
