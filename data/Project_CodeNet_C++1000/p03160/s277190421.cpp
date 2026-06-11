#include<bits/stdc++.h>
using namespace std;

int fun(int cur, vector<int> &dp,vector<int> &h){
	if(dp[cur]!=-1) return dp[cur];
	dp[cur] = min(fun(cur-1,dp,h) + abs(h[cur]-h[cur-1]),fun(cur-2,dp,h) + abs(h[cur]-h[cur-2]));
	return dp[cur];
}
int main(){
	long long int n,x;
	cin>>n;
	vector<int> h;
	vector<int> dp(n,-1);
	for(int i=0;i<n;i++){
		cin>>x;
		h.push_back(x);
	}
	dp[0]=0;
	dp[1] = abs(h[1]-h[0]);
	cout<<fun(n-1,dp,h)<<endl;
}