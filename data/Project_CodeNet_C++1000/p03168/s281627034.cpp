#include "bits/stdc++.h"
using namespace std;

#define ff first
#define ss second
#define pb push_back
#define int long long


signed main(){

int mod=1000000007;

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#else
// online submission
#endif

int n;
cin >> n;
long double arr[n+1] ;

for(int i=1;i<=n;i++)
cin >> arr[i] ;

long double  dp[3000] ={0};


for(int i=0;i<=n;i++){

for(int j=i ; j >=0 ; j--)	{

if(i==0 && j==0){
	dp[j]=1.0;
}

else if(i==0){
dp[j]=0.0;	
}

else if(j==0){
	dp[j]=dp[j]*(1-arr[i]);
}
else 
dp[j]=dp[j-1]*arr[i] + dp[j]*(1-arr[i]) ;

//cout<<dp[j] ;
	
}

}


long double ans=0;
for(int i=n/2+1 ; i <= n ; i++ ){
	ans+=dp[i];
}
cout<<setprecision(10)<<ans;
	return 0;
    
}


