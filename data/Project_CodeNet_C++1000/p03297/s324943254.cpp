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

int gcd(int a, int b) {
  if (b==0) return a;
  return gcd(b,a%b);
}


signed main() {
	int t;
	std::cin >> t;
	rep(tt,t) {
		int a,b,c,d;
		std::cin >> a >> b >> c >> d;
		if(b>a) print("No");
		else if(b>d) print("No");
		else if(c>=b) print("Yes");
		else {
			int g=gcd(b,d);
			if(c<b-g+a%g) print("No");
			else print("Yes");
		}
	}
	return 0;
}
