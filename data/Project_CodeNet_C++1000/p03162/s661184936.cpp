#include<bits/stdc++.h>
using namespace std;
#define PB push_back
#define ll long long

int main(){
#ifndef ONLINE_JUDGE
	freopen("C:\\Users\\User\\Documents\\input.txt","r",stdin);
#endif
	int T,i,j;
	int n;
	cin>>n;

	vector<vector<int> > a(n,vector<int>(3) ),dp(n,vector<int>(3,0) );

	for(i=0;i<n;++i){
		scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
	}
	dp[0][0]=a[0][0],dp[0][1]=a[0][1],dp[0][2]=a[0][2];

	for(i=1;i<n;++i){
		dp[i][0]=max(dp[i-1][1],dp[i-1][2])+a[i][0];
		dp[i][1]=max(dp[i-1][0],dp[i-1][2])+a[i][1];
		dp[i][2]=max(dp[i-1][0],dp[i-1][1])+a[i][2];		
	} 		
	printf("%d\n",max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2])) );
	return 0;
}