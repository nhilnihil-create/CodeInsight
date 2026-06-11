#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long int lli;
const lli mod = 1e9+7;

int main(){
	string s;
	cin >> s;
	vector<vector<lli>> dp(4, vector<lli>(s.length()+1, 0));
	dp[0][0] = 1;
	for(int i=0; i<(int)s.length(); i++){
		for(int d=0; d<3; d++){
			dp[d][i] %= mod;
			if(s[i] == ('A'+d)){
				dp[d+1][i+1] += dp[d][i];
				dp[d][i+1] += dp[d][i];
			}else if(s[i] == '?'){
				dp[d+1][i+1] += dp[d][i];
				dp[d][i+1] += dp[d][i] *3;
			}else{
				dp[d][i+1] += dp[d][i];
			}
		}
		dp[3][i] %= mod;
		if(s[i] == '?'){
			dp[3][i+1] += dp[3][i] *3;
		}else{
			dp[3][i+1] += dp[3][i];
		}
	}
	cout << dp[3][s.length()] %mod << endl;
	return 0;
}