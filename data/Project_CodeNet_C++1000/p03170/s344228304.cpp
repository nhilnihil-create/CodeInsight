#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
int main(){
	int n,k;
	cin>>n>>k;
	int a[n];
	f(i,n)cin>>a[i];
	vector<int> dp(k+1,1);
	// memset(dp,1,sizeof dp)    ;
	//keeps track of winners
// cout<<dp[1]<<endl;
	dp[0]=1;
	for(int i=1;i<=k;i++){
		for(int j=0;j<n;j++){
			if(a[j]<=i)dp[i]=min(dp[i],1-dp[i-a[j]]);
		}
	}
	dp[k]==0?cout<<"First"<<endl:cout<<"Second"<<endl;		//1 is second and 0 is first
	return 0;
}
