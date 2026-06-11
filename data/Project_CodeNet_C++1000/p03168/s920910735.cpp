#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	double arr[n+1];
	for (int i=1;i<=n;i++){
		cin>>arr[i];
	}
	double dp[n+1][n+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			dp[i][j]=0;
		}
	}
	
	dp[1][0]=1.0-arr[1];
	for(int i=2;i<n+1;i++){
		dp[i][0]=(1.0-arr[i])*dp[i-1][0];
	}
	dp[1][1]=arr[1];
	for(int i=2;i<n+1;i++){
		dp[i][i]=arr[i]*dp[i-1][i-1];
	}
	for (int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			dp[i][j]=arr[i]*dp[i-1][j-1]+(1.0-arr[i])*dp[i-1][j];	
		}
	}
	double s;
	for(int i=n/2+1;i<n+1;i++){
		s+=dp[n][i];
	}
	cout<<fixed<<setprecision(10)<<s<<endl;
}