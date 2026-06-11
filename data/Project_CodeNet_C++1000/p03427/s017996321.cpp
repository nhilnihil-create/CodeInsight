#include <bits/stdc++.h>
using namespace std;

int arr[20];
int dp[20][160][2];
int getsum(int ind,int n,int sum, int flag){
	if(ind == n) return sum;
	if(dp[ind][sum][flag]!=-1) return dp[ind][sum][flag]; 
	int limit = 9;
	if(!flag) limit = arr[ind];
	int ans  = -1;
	for(int i=0;i<=limit;i++){
		if(flag || i<arr[ind]) ans = max(ans,getsum(ind + 1, n, sum + i, 1));
		else ans  = max(ans, getsum(ind + 1, n, sum + i, 0));
	}
	return dp[ind][sum][flag] = ans;
}

int main() {

//	int t;
//	cin>>t;
//	while(t--){
		long long a;
		cin>>a;
		
		string aa = to_string(a);
		for(int i=0;i<20;i++) for(int j=0;j<160;j++) for(int k=0;k<2;k++) dp[i][j][k]=-1;
		
		for(int i=0;i<aa.size();i++) arr[i] = aa[i] - '0';
		long long ans = getsum(0,aa.size(),0, 0);
		cout<<ans<<endl;
//	}

}