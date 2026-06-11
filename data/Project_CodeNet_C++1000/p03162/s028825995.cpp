#include<bits/stdc++.h>
#define mx 1000000007
#define ll long long int

using namespace std;

int n,k;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>> n;
    int arr[n+1][4];
    for(int i=1;i<=n;++i)
        cin>> arr[i][1] >> arr[i][2] >> arr[i][3] ;
    int dp[n+1][4]={0};
    dp[n][0]=max(arr[n][1],max(arr[n][2],arr[n][3]));
    dp[n][1]=max(arr[n][2],arr[n][3]);
    dp[n][2]=max(arr[n][1],arr[n][3]);
    dp[n][3]=max(arr[n][1],arr[n][2]);
    for(int i=n-1;i>0;--i){
    	dp[i][0]=max(dp[i+1][1]+arr[i][1],max(dp[i+1][2]+arr[i][2],dp[i+1][3]+arr[i][3]));
    	dp[i][1]=max(dp[i+1][2]+arr[i][2],dp[i+1][3]+arr[i][3]);
    	dp[i][2]=max(dp[i+1][1]+arr[i][1],dp[i+1][3]+arr[i][3]);
    	dp[i][3]=max(dp[i+1][1]+arr[i][1],dp[i+1][2]+arr[i][2]);
    }
    cout<< dp[1][0] ;
	return 0;
}
