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

// ceil of a/b
inline int ceildiv(int a, int b) { return (a+b-1)/b; }

signed main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];
	int sum=0;
	rep(i,n) sum+=a[i];
	constexpr int N = 2e3;
	std::bitset<N*N+1> set;
	set[0]=1;
	rep(i,n) set|=set<<a[i];
	int x=ceildiv(sum,2);
	int j=0;
	for(int i=x;i<=N*N;i++) {
		if(!set[i]) continue;
		print(i);
		break;
	}

	return 0;
}
