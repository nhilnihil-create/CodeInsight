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

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ENDL '\n'
#define print(i) std::cout << (i) << '\n'

#define int long long // at least int64 > 9*10^18
#define all(v) (v).begin(), (v).end()
/* libraries */

#define dump1(v) for(auto i:v) std::cout << i << ' '; std::cout << "\n";
#define dump2(v) for(auto i:v) { for(auto j:i) std::cout << j << ' '; std::cout << "\n"; }


const int MOD = 1e9+7;
signed main() {
	int n;
	std::cin >> n;
	std::vector<int> c;
	rep(i,n) {
		int a;
		std::cin >> a;
		if(i==0) c.emplace_back(a);
		else if(c.back()!=a) c.emplace_back(a);
	}
	n = c.size();
	std::vector<int> dp(n,0);
	std::map<int,std::vector<int> > map;
	dp[0] = 1;
	map[c[0]].emplace_back(0);
	for(int i=1;i<n;i++) {
		int sum = dp[i-1];
		if(!map[c[i]].empty()) {
			int x = map[c[i]].back();
			sum+=dp[x];
			sum%=MOD;
		}
		dp[i] = sum;
		map[c[i]].emplace_back(i);
	}
	print(dp[n-1]);
	return 0;
}
