#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
#define ALL(v) (v).begin(),(v).end()
typedef long long LL;
const int INF = 1 << 25;
const LL MOD = 1000000007LL;
using namespace std;
int dp[1 << 26];
int main() {
	string s;
	cin >> s;
	int bit = 0, opt;
	fill(dp, dp + (1 << 26), INF);
	dp[0] = 0;
	rep(i, s.size()) {
		bit ^= (1 << (s[i] - 'a'));
		opt = INF;
		rep(j, 26) {
			opt = min(opt, dp[bit ^ (1 << j)] + 1);
		}
		if (bit == 0) opt = 1;
		dp[bit] = min(dp[bit], opt);
	}
	cout << opt << endl;
}