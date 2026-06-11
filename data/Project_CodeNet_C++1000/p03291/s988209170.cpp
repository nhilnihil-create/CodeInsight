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

const int MOD = 1e9+7;

signed main() {
	std::string s;
	std::cin >> s;
	std::vector<int> d(4,0);
	std::vector<int> p(4,0);
	d[0] = 1;
	for(auto c:s) {
		rep(i,4) {
			if(c=='?') {
				p[i] = d[i]*3;
				p[i] %= MOD;
			}
			else p[i] = d[i];
		}
		if(c=='A' || c=='?') p[1] = (p[1] + d[0])%MOD;
		if(c=='B' || c=='?') p[2] = (p[2] + d[1])%MOD;
		if(c=='C' || c=='?') p[3] = (p[3] + d[2])%MOD;
		std::swap(d,p);
	}
	print(d[3]);
	return 0;
}
