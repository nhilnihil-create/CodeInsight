#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
string S;
//# . 
int dp[200009][2];

void solve()
{
	memset(dp,0x3f,sizeof(dp));
	if(S[0] == '#'){
		dp[0][1] = 0;
		dp[0][0] = 1;
	}else{
		dp[0][1] = 1;
		dp[0][0] = 0;
	}
	for(int i=1;i<N;++i){
		if(S[i] == '#'){
			dp[i][1] = min(dp[i-1][0],dp[i-1][1]);
			dp[i][0] = dp[i-1][0]+1;
		}else{
			dp[i][1] = min(dp[i-1][0],dp[i-1][1])+1;
			dp[i][0] = dp[i-1][0];
		}
	}
	cout << min(dp[N-1][0],dp[N-1][1]) << '\n';
}

int main()
{
	cin >> N >> S;
	solve();
	return 0;
}