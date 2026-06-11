#include<bits/stdc++.h>
using namespace std;
long long M=1e9+7;
int solve(){
	int n,K,x,y,p,q;
	cin>>n>>K;
	vector<int>A(n);
	for(int i=0;i<n;i++) cin>>A[i];
	long long dp[n][K+1];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=min(A[0],K);i++) dp[0][i]=1;
	for(int i=1;i<n;i++){
		//check 7 dec 16 in diary for solution;
		x=min(A[i],K);
		dp[i][0]=1;
		// cout<<x<<"\n";
		for(int k=1;k<=x;k++){
			dp[i][k]=(dp[i][k-1]+dp[i-1][k])%M;
		}
		for(int k=x+1;k<=K;k++){
			dp[i][k]=(dp[i-1][k]+dp[i][k-1]-dp[i-1][k-1-x]+M)%M;	
		}
		
	}
	return dp[n-1][K];

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout<<solve()<<"\n";

}