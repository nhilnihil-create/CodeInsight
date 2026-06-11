#include<bits/stdc++.h>
using namespace std;
 
int main(){
	int n;
	cin>>n;
	vector<long long> v(n);
	vector<long long> sum(n);
	for(long long i=0;i<n;i++){
		cin>>v[i];
		if(i==0)
 			sum[i]=v[i];
		else
			sum[i]=v[i]+sum[i-1];	
	}
	vector<vector<long long> > dp(n,vector <long long> (n,0));
	for(long long j=0;j<n;j++){
		for(long long i=j-1;i>=0;i--){
			dp[i][j]=10e15;
			for(long long k=i;k<j;k++){
	 			long long s=0;
	 			s=sum[j];
				if(i>0)
	 				s-=sum[i-1];
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+s);	
			}	
		}
	 }
	cout<<dp[0][n-1]<<endl;
	return 0;
}