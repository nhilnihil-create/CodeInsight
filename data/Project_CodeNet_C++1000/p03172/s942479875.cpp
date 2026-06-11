//Use prefix sum
// dp[i][j] = j candies for first i students
// ith student can tak 0 to a[i] candies so dp[i][j]=(dp[i-1][0]+dp[i-1][1] ... dp[i-1][j]) hence use prefix sum

#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main() {
	// your code goes here
	ll n,k;cin>>n>>k;
	ll a[n];
	for(int i=1;i<=n;i++)cin>>a[i];
	
	a[0]=0;
	ll M=1e9+7;
	ll dp[n+1][k+1]={0},prefix[n+1][k+1]={0};
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			
			if(j==0){
				dp[i][j]=1;
				prefix[i][j]=1;
			}else if(i==0){
				dp[i][j]=0;
				prefix[i][j]=prefix[i][j-1];
			}else if(j>a[i]){
				dp[i][j]=(prefix[i-1][j]-prefix[i-1][j-a[i]-1])%M;
				prefix[i][j]=(prefix[i][j-1]+dp[i][j]);
			}else{
				dp[i][j]=prefix[i-1][j]%M;
				prefix[i][j]=(prefix[i][j-1]+dp[i][j]);
			}
		}
	}
 
/*	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			cout<<dp[i][j]<<" ";
		}cout<<endl;
	}
 
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			cout<<prefix[i][j]<<" ";
		}cout<<endl;
	}
 */
 
 cout<<dp[n][k]<<endl;
 
	/*
	if(sum<k){
		cout<<0<<endl;
	}else{
 
	}
	*/
	return 0;
}