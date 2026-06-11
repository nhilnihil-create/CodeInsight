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

signed main() {
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	std::string l,r;
	l=s.substr(0,n);
	r=s.substr(n,n);
	std::reverse(all(r));
	int count=0;
	std::map<std::pair<std::string,std::string>, int> map;
	rep(ss,1<<n) {
		std::string x,y;
		rep(i,n) {
			if(ss>>i&1) x+=l[i];
			else y+=l[i];
		}
		map[std::make_pair(x,y)]++;
	}
	rep(ss,1<<n) {
		std::string x,y;
		rep(i,n) {
			if(ss>>i&1) x+=r[i];
			else y+=r[i];
		}
		count+=map[std::make_pair(x,y)];
	}
	print(count);
	return 0;
}
