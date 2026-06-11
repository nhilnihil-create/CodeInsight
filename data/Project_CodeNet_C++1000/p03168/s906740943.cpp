#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	vector<double> dp(n+1,0);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		double k;cin>>k;
		for(int j=i;j>=0;j--){
			dp[j]=(i==0?0:dp[j-1]*k) + dp[j]*(1-k);
		}
	}
	double s=0;
	for(int i=n/2+1;i<=n;i++) s+=dp[i];
		printf("%.10lf\n",s);
}