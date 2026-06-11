#include<bits/stdc++.h>
using namespace std;

int main(){
  	int N;
  	cin>>N;
  	vector<double> A(N);
  	for(int i=0;i<N;i++){
    	cin>>A[i];
    }
  	vector<vector<double>> dp(N+1,vector<double>(N+1,0.0));
  	dp[1][0]=1.0-A[0];
  	dp[1][1]=A[0];
  	for(int i=2;i<=N;i++){
    	for(int j=0;j<=i;j++){
        	if(j==0)	dp[i][j]=dp[i-1][j]*(1.0-A[i-1]);
          	else{
            	dp[i][j]= dp[i-1][j]*(1.0-A[i-1]) + dp[i-1][j-1]*A[i-1];
            }
        }
    }
  	double ans=0.0;
	for(int i=(N+1)/2;i<=N;i++){
      	ans+=dp[N][i];
    }
  	cout<<setprecision(10)<<ans;
	return 0;
}