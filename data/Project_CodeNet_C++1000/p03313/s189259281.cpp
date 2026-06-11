#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <iomanip>
#include <functional>
#include <bitset>
#include <limits>
#include <cstdio>
#include <cmath>
#include <cassert>
#include <random>

#ifdef DEBUG
#include "library/Utility/debug.cpp"
#else
#define debug(...)
#endif

#define rep(i,n) for(int i=0;i<(n);++i)
#define EL '\n'
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
using lnt = long long;
struct FIO{FIO(){std::cin.tie(0);std::cout.tie(0);std::ios_base::sync_with_stdio(0);std::cout<<std::setprecision(15);}}fIO;
template<typename T> using V = std::vector<T>;
template<typename T> void fill(V<T>&v) { for(T&e:v) std::cin >> e; }
/*-*/

int main() {
	int n;
	std::cin >> n;
	V<lnt> a(1<<n);
	fill(a);
	int max=0;
	V<std::pair<std::pair<int,int>,std::pair<int,int> > > dp(1<<n);
	/*
	rep(i,n) {
		dp[1<<i]=std::make_pair(std::make_pair(a[0],0),std::make_pair(a[1<<i],1<<i));
	}
	*/
	for(int k=1;k<(1<<n);k++) {
		std::set<std::pair<int,int> > set;
		rep(i,n) {
			if(k&(1<<i)) {
				if((k^(1<<i))==0) set.emplace(a[0],0);
				else {
					auto p=dp[k^(1<<i)];
					set.emplace(p.first);
					set.emplace(p.second);
				}
			}
		}
		set.emplace(a[k],k);
		auto f=*set.rbegin();
		dp[k].first=f;
		set.erase(f);
		auto s=*set.rbegin();
		dp[k].second=s;
		max=std::max(max,f.first+s.first);
		print(max);
	}
}
