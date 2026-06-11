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
		A[i]*=B;
		A[i]+=i;
	}
	
	vector<vector<pair<long long,long long>>> dp((1<<N),vector<pair<long long,long long>> (N+1));
	
	for(int i=0;i<=N;i++){
		for(int j=0;j<(1<<N);j++){
			if(i==0){
				dp[j][i] = make_pair(0,A[j]);
			}
			else{
				vector<long long> V;
				V.push_back(dp[j][i-1].first);
				V.push_back(dp[j][i-1].second);
				if((j>>(i-1))&1){
					V.push_back(dp[j&(~(1<<(i-1)))][i-1].first);
					V.push_back(dp[j&(~(1<<(i-1)))][i-1].second);
				}
				sort(V.rbegin(),V.rend());
				V.erase(unique(V.begin(),V.end()),V.end());
				dp[j][i].first = V[0];
				dp[j][i].second = V[1];
			}
		}
	}
	
	vector<long long> ans(1<<N);
	
	for(int i=0;i<(1<<N);i++){
		ans[i] = dp[i][N].first/B + dp[i][N].second/B;
		if(i!=0)ans[i] = max(ans[i],ans[i-1]);
	}
	
	for(int i=1;i<(1<<N);i++){
		printf("%lld\n",ans[i]);
		//cout<<ans[i]<<endl;
	}
	
	
	
    return 0;
}