#include<bits/stdc++.h>
#define ll long long
ll mod = 1e9+7;
using namespace std;

int main(){
	
	int H,W ;
	cin>>H>>W;
	char arr[H][W];
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			cin>>arr[i][j];
		}
	}
	ll dp[H][W];
	memset(dp, 0, sizeof(dp));
	dp[H-1][W-1]=1;
	for(int i=W-2;i>=0;i--) {
		if(arr[H-1][i]=='.'){
			dp[H-1][i]+=dp[H-1][i+1];
		}
	}
	for(int i=H-2;i>=0;i--) {
		if(arr[i][W-1]=='.'){
			dp[i][W-1]+=dp[i+1][W-1];
		}
	}
	for(int i=H-2;i>=0;i--){
		for(int j=W-2;j>=0;j--){
			if(arr[i][j]=='.'){
				dp[i][j]= (dp[i][j+1]%mod + dp[i+1][j]%mod )%mod;
			}
		}
	}
	ll ans= dp[0][0]%mod;
	cout<<ans<<endl;
	return 0;
	
}
