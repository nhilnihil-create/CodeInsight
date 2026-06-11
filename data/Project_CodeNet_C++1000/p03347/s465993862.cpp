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

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...)
#endif

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ENDL '\n'
#define print(i) std::cout << (i) << '\n'

#define int long long // at least int64 > 9*10^18
#define all(v) (v).begin(), (v).end()
/* libraries */

signed main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];
	if(a[0] != 0) {
		print(-1);
		return 0;
	}
	int sum = 0;
	int atleast = 0;
	for(int i=n-1;i>=1;i--) {
		atleast--;
		if(atleast>a[i]) {
			print(-1);
			return 0;
		}
		if(atleast<a[i]) {
			sum+=a[i];
		}
		atleast = a[i];
	}
	print(sum);

	return 0;
}
