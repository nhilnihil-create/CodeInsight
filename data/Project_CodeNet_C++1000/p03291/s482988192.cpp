#include <iostream> // cin, cout, cerr, clog
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota, accumulate, inner_product
#include <cstdio> // printf, scanf
#include <climits> // INT_MIN, LLONG_MIN
#include <cmath> // long, trig, pow
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <stack> // stack
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <unordered_map> // hashed by keys
#include <unordered_set> // hashed by keys
#include <iomanip> // cout<<setprecision(n)
#include <functional> // std::function<void(int)>

#define rep(i,n) for(int i = 0; i < n; i++)
#define ENDL "\n"
#define print(i) std::cout << (i) << "\n"

#define int long long // at least int64 > 9*10^18
#define all(v) v.begin(), v.end()

#define dump1(v) for(auto i:v) std::cout << i << ' '; std::cout << "\n";
#define dump2(v) for(auto i:v) { for(auto j:i) std::cout << j << ' '; std::cout << "\n"; }
const int MOD = 1e9+7;

int modpow(int v,int k){int r(1),t(v);while(k){if(k&1){r*=t;r%=MOD;}t*=t;t%=MOD;k>>=1;} return r;}

signed main() {
	std::string s;
	std::cin >> s;
	std::vector<std::vector<int> > dp(s.size()+1,std::vector<int>(4,0));
	dp[0][3] = 1;
	rep(i,s.size()) {
		if(s[i]=='A') {
			dp[i+1][0] = (dp[i][0]+dp[i][3])%MOD;
			dp[i+1][1] = dp[i][1];
			dp[i+1][2] = dp[i][2];
			dp[i+1][3] = dp[i][3];
			continue;
		}
		if(s[i]=='B') {
			dp[i+1][0] = dp[i][0];
			dp[i+1][1] = (dp[i][0]+dp[i][1])%MOD;
			dp[i+1][2] = dp[i][2];
			dp[i+1][3] = dp[i][3];
			continue;
		}
		if(s[i]=='C') {
			dp[i+1][0] = dp[i][0];
			dp[i+1][1] = dp[i][1];
			dp[i+1][2] = (dp[i][1]+dp[i][2])%MOD;
			dp[i+1][3] = dp[i][3];
			continue;
		}
		if(s[i]=='?') {
			dp[i+1][0] = (dp[i][0]*3+dp[i][3])%MOD;
			dp[i+1][1] = (dp[i][0]+dp[i][1]*3)%MOD;
			dp[i+1][2] = (dp[i][1]+dp[i][2]*3)%MOD;
			dp[i+1][3] = (dp[i][3]*3)%MOD;
			continue;
		}
	}
	print(dp[s.size()][2]);

	return 0;
}
