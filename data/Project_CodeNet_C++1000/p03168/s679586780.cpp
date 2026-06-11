#include<bits/stdc++.h>
using namespace std;
//#define float double
int main(){
	int n;
	cin>>n;
	cout<<fixed<<setprecision(10);
	double p[n];
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	vector<vector<double>> dp(n+1 ,vector<double>(n+1,0.0));//dp[i][j] = probabilty of getting j heads with i coins
	for(int i=0;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(i==0 && j==0)
				dp[i][j]=1;
			else if(j==0)
				dp[i][j]=dp[i-1][j]*(1-p[i-1]);
			else
			//probabilty of getting j heads 
			// if there are already j heads, toss tail
			// else if j-1 heads, heads
				dp[i][j]=p[i-1]*dp[i-1][j-1] + (1-p[i-1])*dp[i-1][j];	
		}
	}
	double ans=0.0;
	/*for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++)
		cout<<dp[i][j]<<" ";
		cout<<"\n";
	}*/
	for(int i=0;i<=n;i++){
		if(i>n/2)
		ans+=dp[n][i];
	}
	cout<<ans<<"\n";
	return 0;
}