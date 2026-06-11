#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<unordered_set>
#include<unordered_map>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<double> p(n+1);
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	vector<double> dp(n+1);
	dp[0]=1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j>=0;j--){
		    dp[j] = (j==0?0:dp[j-1]*p[i]) + dp[j]*(1-p[i]) ;	
		}
	}
	double ans=0;
	for(int heads=0;heads<=n;heads++){
		int tails = n-heads;
		if(heads>tails)
		    ans+=dp[heads];
	}
	cout.precision(10);
	cout<<ans;
	return 0;
}
