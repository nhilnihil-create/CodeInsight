#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;

	int a[n+5][3];

	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
	}

	int dp[3][n+1];

	memset(dp,0,sizeof(dp));

	for(int i=0;i<3;i++){
		dp[i][0]=a[0][i];
	}

	for(int i=1;i<n;i++){
		dp[0][i]=max(dp[1][i-1],dp[2][i-1])+a[i][0];
		dp[1][i]=max(dp[0][i-1],dp[2][i-1])+a[i][1];
		dp[2][i]=max(dp[1][i-1],dp[0][i-1])+a[i][2];
	}


	int res=max(dp[0][n-1],max(dp[1][n-1],dp[2][n-1]));
	cout<<res<<endl;
	return 0;
}
		
