// C - Strange Bank
#include <bits/stdc++.h>
using namespace std;

int main(){
	int coin[12] = {1,6,36,216,1296, 7776,46656,9,81,729,6561,59049};
	int inf = 1e9;
	int n; cin>>n;
	vector<int> dp(n+1, inf);
	dp[0] = 0;
	for(int c:coin)
		for(int yen=c; yen<=n; ++yen)
			dp[yen] = min(dp[yen], dp[yen-c] + 1);
	cout<< dp[n] <<endl;
}
