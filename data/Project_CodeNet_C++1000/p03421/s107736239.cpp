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
/* libraries */

// ceil of a/b
inline int ceil(int a, int b) { return (a+b-1)/b; }

signed main() {
	int n,a,b;
	std::cin >> n >> a >> b;
	if(n-b+1<a || a<ceil(n,b)) {
		print(-1);
		return 0;
	}
	if(n==a) {
		for(int i=1;i<=n;i++) std::cout << i << ' ';
		std::cout << EL;
	} else {
		int x=(n-a)/(b-1);
		int y=a-ceil(n-a,b-1);
		int i=1;
		rep(j,y) std::cout << i++ << ' ';
		rep(j,x) {
			i+=b;
			rep(k,b) std::cout << i-k-1 << ' ';
		}
		int j=n;
		while(j>=i) std::cout << j-- << ' ';
		std::cout << EL;
	}
	return 0;
}
