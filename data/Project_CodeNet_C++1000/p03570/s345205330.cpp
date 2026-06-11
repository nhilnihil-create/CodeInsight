#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000


int main(){
	
	string S;
	cin>>S;
	
	vector<int> dp(1<<26,Inf);
	dp[0] = 0;
	
	int now = 0;
	for(int i=0;i<S.size();i++){
		now ^= 1<<(S[i]-'a');
		for(int j=0;j<26;j++){
			dp[now] = min(dp[now],dp[now^(1<<j)]+1);
		}
	}
	
	if(now!=0)cout<<dp[now]<<endl;
	else cout<<1<<endl;

	return 0;
}