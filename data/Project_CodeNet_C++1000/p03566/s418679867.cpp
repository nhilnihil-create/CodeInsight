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

struct I
{
	int l,r,v;
	I(int l, int r, int v) : l(l),r(r),v(v) {}
	double f(double t) {
		if(t>r) return v+t-r;
		if(t<l) return v+l-t;
		return v;
	}
};

signed main() {
	int n;
	std::cin >> n;
	std::vector<I> c;
	int tl=0;
	{
		std::vector<int> t(n),v(n);
		rep(i,n) std::cin >> t[i];
		rep(i,n) std::cin >> v[i];
		c.emplace_back(0,0,0);
		rep(i,n) {
			c.emplace_back(tl,t[i]+tl,v[i]);
			tl+=t[i];
		}
		c.emplace_back(tl,tl,0);
	}
	debug(tl);
	double sum=0;
	for(int ct2=0;ct2<tl*2;ct2++) {
		double ct=ct2*(double)0.5;
		double dt=0.5;
		double min0=1e9,min1=1e9;
		for(auto x:c) {
			min0=std::min(min0,x.f(ct));
			min1=std::min(min1,x.f(ct+dt));
		}
		sum+=(min0+min1)*dt*(double)0.5;
	}
	std::cout << std::setprecision(10) << sum << EL;

	return 0;
}
