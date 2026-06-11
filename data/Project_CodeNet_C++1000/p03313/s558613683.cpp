#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){
	
	int N;
	cin>>N;
	
	vector<long long> A(1<<N);
	
	long long B = 1000000;
	
	for(int i=0;i<(1<<N);i++){
		scanf("%lld",&A[i]);
	}
	
	vector<vector<pair<long long,long long>>> dp(2,vector<pair<long long,long long>> (1<<N));
	vector<long long> V(4);
	for(int i=0;i<=N;i++){
		for(int j=0;j<(1<<N);j++){
			if(i==0){
				dp[0][j] = make_pair(0,A[j]);
			}
			else{
				if((j>>(i-1))&1){
					V[0] = dp[1][j].first;
					V[1] = dp[1][j].second;
					V[2] = dp[1][j&(~(1<<(i-1)))].first;
					V[3] = dp[1][j&(~(1<<(i-1)))].second;
					sort(V.rbegin(),V.rend());
					//V.erase(unique(V.begin(),V.end()),V.end());
					dp[0][j].first = V[0];
					dp[0][j].second = V[1];
				}
				else dp[0][j] = dp[1][j];
			}
		}
		swap(dp[0],dp[1]);
	}
	
	//vector<long long> ans(1<<N);
	
	for(int i=0;i<(1<<N);i++){
		dp[1][i].first += dp[1][i].second;
		if(i!=0)dp[1][i].first = max(dp[1][i].first,dp[1][i-1].first);
	}
	
	for(int i=1;i<(1<<N);i++){
		printf("%lld\n",dp[1][i].first);
		//cout<<ans[i]<<endl;
	}
	
	
	
    return 0;
}