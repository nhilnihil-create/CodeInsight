#include<bits/stdc++.h>
using namespace std;

int fun(int cur,vector<long long int> &dp,vector<long long int> &h,int k){
	if(dp[cur]!=-1) return dp[cur];
	long long int ans=1e10;
	for(int i=max(0,cur-k);i<cur;i++){
		ans = min(ans,fun(i,dp,h,k) + abs(h[cur]-h[i]));
	}
	dp[cur]=ans;
	return dp[cur];
}
int main(){
	long long int n,x,k;
	cin>>n>>k;
	vector<long long int> h,dp(n,-1);
	for(int i=0;i<n;i++){
		cin>>x;
		h.push_back(x);
	}
	dp[0]=0;
	dp[1] = abs(h[1]-h[0]);
	cout<<fun(n-1,dp,h,k)<<endl;
}