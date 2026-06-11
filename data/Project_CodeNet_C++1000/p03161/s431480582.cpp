#include<bits/stdc++.h>
#define mx 1000000007
#define ll long long int

using namespace std;

int n,k;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>> n >> k ;
    int arr[n+1];
    for(int i=1;i<=n;++i)
        cin>> arr[i] ;
    int dp[n+1]={0};
    dp[n-1]=abs(arr[n-1]-arr[n]);
    for(int i=n-2;i>0;--i){
    	int mini=mx;
    	for(int j=i+1;(j<=n && j<=i+k) ;++j){
    		if(dp[j]+abs(arr[i]-arr[j])<mini)
    			mini=dp[j]+abs(arr[i]-arr[j]);
    	}
    	dp[i]=mini;
    }
    cout<< dp[1] ;
	return 0;
}
