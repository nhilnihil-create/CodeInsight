#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll k,a,dp[2<<17],m=1e9+7;
int i,n,j;
main(){
	cin>>n>>k;
	dp[0]=1;
	for(i=0;i<n;i++){
		cin>>a;
		for(j=1;j<=k;j++)dp[j]+=dp[j-1];
		for(j=k;j>=1;j--) 
		{if(j-a-1>=0) dp[j]=(dp[j]-dp[j-a-1])%m;
		else dp[j]%=m;}
	}
	cout<<dp[k];
}