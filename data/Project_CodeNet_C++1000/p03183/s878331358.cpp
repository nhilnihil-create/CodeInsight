#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000001


int main(){
	
	int N;
	cin>>N;
	
	vector<vector<int>> V(N);
	for(int i=0;i<N;i++){
		int w,s,v;
		cin>>w>>s>>v;
		
		V[i] = {w+s,w,s,v};
	}
	
	sort(V.begin(),V.end());
	
	vector<vector<long long>> dp(N+1,vector<long long>(20001,-Inf));
	dp[0][0] = 0;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<=20000;j++){
			if(dp[i][j]==-Inf)continue;
			dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
			if(j>V[i][2])continue;
			int to = j + V[i][1];
			if(to<=20000)dp[i+1][to] = max(dp[i+1][to],dp[i][j]+V[i][3]);
		}
	}
	
	long long ans = 0;
	for(int i=0;i<dp.back().size();i++)ans = max(ans,dp.back()[i]);
	
	cout<<ans<<endl;
		
	return 0;
}
