#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){

	int N;
	cin>>N;
	
	vector<int> C(N);
	for(int i=0;i<N;i++){
		cin>>C[i];
	}
	
	vector<int> dp(N,1);
	
	vector<int> cnt(200002,0);
	cnt[C[0]]=1;
	
	for(int i=1;i<N;i++){
		if(C[i]==C[i-1]){
			dp[i] = dp[i-1];
		}
		else{
			int K = dp[i-1];
			K = mod(K + cnt[C[i]]);
			dp[i] = K;
			cnt[C[i]] = mod(cnt[C[i]] + dp[i-1]);
		}
	}
	
	cout<<dp.back()<<endl;
	
	return 0;
}