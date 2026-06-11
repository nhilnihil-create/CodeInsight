#include<bits/stdc++.h>
using namespace std;
long long int dp[101][100001];

main(){
long long int n,k;
cin>>n>>k;
long long int ar[n];
for(int i=0;i<n;i++)cin>>ar[i];
//memset(dp,1,sizeof(dp));

for(int i=0;i<n;i++)dp[i][0]=1;


for(int i=0;i<n;i++)for(int j=1;j<=k;j++)
{
if(i==0){if(j<=ar[i])dp[i][j]=1;
	else{  dp[i][j]=0;} }
	
else{
dp[i][j]=(dp[i-1][j]+dp[i][j-1]);


	if(ar[i]<j){dp[i][j]-=dp[i-1][j-1-ar[i]];}
}
//cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;

dp[i][j]=(1000000007+dp[i][j])%1000000007;

}
cout<<dp[n-1][k];



}
