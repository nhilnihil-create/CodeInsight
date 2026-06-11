#include<bits/stdc++.h>
#define mx 1000000007
#define ll long long int

using namespace std;

int n;

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>> n;
    int arr[n+1];
    for(int i=1;i<=n;++i)
        cin>> arr[i] ;
    int dp[n+1]={0};
    dp[n-1]=abs(arr[n-1]-arr[n]);
    for(int i=n-2;i>0;--i)
    	dp[i]=min(abs(arr[i]-arr[i+1])+dp[i+1],abs(arr[i]-arr[i+2])+dp[i+2] );
    cout<< dp[1] ;
	return 0;
}
