#include <bits/stdc++.h>
using namespace std;

signed main() {
	constexpr int INF = 1<<30;

	string S;
	cin >> S;
	int N = S.size();

	vector<int> hash(N);
	int h = 0;
	for(int i=0; i<N; i++){
		h = h ^ (1<<(S[i]-'a'));
		hash[i] = h;
	}

	if(__builtin_popcount(hash.back()) <= 1){
		cout << 1 << endl;
		return 0;
	}

	vector<int> dp(1<<26, INF);
	dp[0]=0;
	for(int i=0; i<N; i++){
		int minval = INF;
		int palindromehash = 0;
		int subtractedhash = palindromehash ^ hash[i];
		minval = min(minval, dp[subtractedhash]+1);
		for(int j=0; j<26 ;j++){
			int palindromehash = 1<<j;
			int subtractedhash = palindromehash ^ hash[i];
			minval = min(minval, dp[subtractedhash]+1);
		}
		dp[hash[i]] = min(minval, dp[hash[i]]);
	}

	cout << dp[hash.back()] << endl;
	return 0;
}
