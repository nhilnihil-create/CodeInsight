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

#ifdef DEBUG
#include "debug.hpp"
#else
#define debug(...)
#endif

#define int long long // at least int64 > 9*10^18
#define ENDL '\n'
#define rep(i,n) for(int i = 0; i < (n); i++)
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
/* libraries */

signed main() {
	int n,k;
	std::cin >> n >> k;
	std::map<int,std::vector<int> > map;
	rep(i,n) {
		int t,d;
		std::cin >> t >> d;
		map[t].emplace_back(d);
	}
	for(auto&&x:map) std::sort(all(x.second),std::greater<int>());
	// get the best of all varieties
	std::vector<int> best;
	for(auto x:map) best.emplace_back(x.second[0]);
	std::vector<int> rest;
	for(auto x:map) for(int i=1;i<x.second.size();i++) rest.emplace_back(x.second[i]);
	std::sort(all(best),std::greater<int>());
	std::sort(all(rest),std::greater<int>());
	std::vector<int> bac(best.size()+1,0);
	std::vector<int> rac(rest.size()+1,0);
	rep(i,best.size()) bac[i+1] = bac[i]+best[i];
	rep(i,rest.size()) rac[i+1] = rac[i]+rest[i];
	int max = 0;
	for(int t=1;t<=std::min(k,(int)best.size());t++) {
		if(t>best.size() || k-t>rest.size()) continue;
		int sum = t*t;
		sum+=bac[t];
		sum+=rac[k-t];
		max = std::max(max,sum);
	}
	print(max);

	return 0;
}
