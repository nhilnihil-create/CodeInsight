#include <iostream> // cin, cout, cerr
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota
#include <cstdio> // printf, scanf
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <iomanip> // cout<<setprecision(n)
#include <functional> // function<void(int)>
#include <cmath>
#include <cassert>
#include <bitset>
#include <stack>

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...)
#endif

#define int long long // at least int64 > 9*10^18
#define EL '\n'
#define rep(i,n) for(int i = 0; i < (n); i++)
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
using Graph = std::vector<std::vector<int> >;
const int INF = 1e17;
/* libraries */

signed main() {
	int n,z,w;
	std::cin >> n >> z >> w;
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];
	if(n==1) {
		print(std::abs(w-a[0]));
		return 0;
	}
	int x=std::abs(a[n-1]-a[n-2]);
	print(std::max(std::abs(w-a[n-1]),x));
	return 0;
}
