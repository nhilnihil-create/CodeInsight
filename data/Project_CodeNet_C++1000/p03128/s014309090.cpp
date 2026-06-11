#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007;
using ll = long long;
using namespace std;

int dp[10050];
const int gs[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main(){
	int n, m; cin >> n >> m;
	vector<int> match(m);
	for( auto &k : match ) cin >> k;
	fill_n( dp, 10000, -1 );
	dp[0] = 0;
	for( int i = 0; i <= n; ++i ){
		for( auto k : match ){
			dp[i+gs[k]] = max(dp[i]+1, dp[i+gs[k]]);
		}
	}
	/*
	cout << "!" << endl;
	for( int i = 0; i <= n; ++i ){
		cout << "dp[" << i << "]: " << dp[i] << endl;
	}
	*/
	vector<int> ans;
	while( n > 0 ){
		int d = -1;
		for( auto k : match ){
			if( n-gs[k] >= 0 && dp[n]-dp[n-gs[k]] == 1 ){
				d = max(d, k);
			}
		}
		ans.push_back(d);
		n -= gs[d];
	}
	sort( ans.begin(), ans.end(), greater<int>() );
	for( auto k : ans ) cout << k;
	cout << endl;
}