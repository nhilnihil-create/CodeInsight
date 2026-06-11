#include <bits/stdc++.h>
using namespace std;
struct iofix
{
	ios_base::Init i;
	iofix() {
		cin.sync_with_stdio(0);
		cin.tie(0);
		cout.sync_with_stdio(0);
		cout.tie(0);
		cout.precision(10);
		cout << fixed;
	}
} iofix;

void solve(){ 
	int N; cin >> N;
	vector<int64_t > dp(3, 0);
	for(int i = 0; i < N; ++i){
		vector <int64_t > cost(3);
		for(int c = 0; c < 3; ++c)
			cin >> cost[c];
		vector <int64_t > new_dp(3, 0);
		for(int j = 0; j < 3 ; ++j){
			for(int k = 0 ; k < 3 ; ++k){
				if(j != k)
			        	new_dp[k] = max(new_dp[k], dp[j] + cost[k]);
			}
		}
		dp = new_dp;
	}
	cout << max({dp[0], dp[1], dp[2]}) << "\n";
}


int main(){

	solve();

#ifndef Time
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
	return 0;
}
