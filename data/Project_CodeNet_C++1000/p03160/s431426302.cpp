#include<bits/stdc++.h>
using namespace std;
vector<int>dp(100000001,-1);
int main(){
	int n;
	cin>>n;
	vector<int> h;
	for(int i=0;i<n;i++){
		int h1;
	    cin>>h1;
	    h.push_back(h1);
	}
	dp[0]=0;
	for(int i=1;i<n;i++){
	    if(i==1)
			dp[i]=abs(h[i-1]-h[i]);
		else		
		dp[i]=min(abs(h[i-2]-h[i])+dp[i-2],abs(h[i-1]-h[i])+dp[i-1]);
	}
	cout<<dp[n-1]<<"\n";
	return 0;
}
