#include<bits/stdc++.h>
using namespace std;
void solve(){
	int n,m;
	cin>>n;
	vector<unsigned long long>A(n);
	for(int i=0;i<n;i++) cin>>A[i];
	unsigned long long sum[n][n];
	memset(sum,0,sizeof(sum));
	for(int i=0;i<n;i++) sum[i][i]=A[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++) sum[i][j]=sum[i][j-1]+A[j];
	}
	unsigned long long dp[n][n]; //dp[i][j] means from i to j
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n-1;i++) dp[i][i+1]=A[i]+A[i+1];
	for(int k=2;k<n;k++){
		for(int i=0;i<n-k;i++){
			int j=i+k;
			dp[i][j]=dp[i][j-1]+sum[i][j]; //jb j end m pure k sath add hoga
			for(int p=j-1;p>i;p--){
				dp[i][j]=min(dp[i][j], dp[p][j]+dp[i][p-1]+sum[i][j]);
			}
		}
	}
	cout<<dp[0][n-1]<<"\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();

}