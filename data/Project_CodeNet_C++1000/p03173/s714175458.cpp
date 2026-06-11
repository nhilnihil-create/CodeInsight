#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1e18
int MOD = 1e9+7;
ll a[403];
ll n,K;
ll dp[403][403];
//N
int main(){
	cin>>n;
	for(int i=0;i<n;++i){ //initialize dp
		for(int j=0;j<n;++j){
			dp[i][j] = (ll)INF;
		}
	}
	vector<ll> pref(n+1);
	for(int i=0;i<n;++i){
		cin>>a[i];
		pref[i+1] = pref[i]+a[i];
	}
	for(int L=1;L<=n;L++){
		for(int i=0;i<=n-L;i++){
			int j = i+L-1;
			if(L==1) {dp[i][j] = 0;continue;}
			ll sum = pref[j+1]-pref[i];
			for(int k=i;k<j;k++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+sum);
			}
		}
	}
	// cout<<endl;cout<<endl;
	// for(int i=0;i<n;++i){ //initialize dp
	// 	for(int j=0;j<n;++j){
	// 		cout<<dp[i][j]<<"           "; 
	// 	}
	// 	cout<<endl;
	// }
	cout<<dp[0][n-1]<<endl;
}