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

template <typename M>
struct SegmentTree
{
	const int n;
	const M I;
	const std::function<M(M,M)> f;
	std::vector<M> data;
	SegmentTree(int n, M I, std::function<M(M,M)> f) : n(n), data(2*n,I), I(I), f(f) {}
	void set(int i, const M& v) {
		data[n+i]=v;
	}
	void build() {
		for(int i=n-1;i>0;i--) {
			data[i]=f(data[i<<1],data[i<<1|1]);
		}
	}
	void update(int i, const M& v) {
		set(i,v);
		i+=n;
		for(i>>=1;i>0;i>>=1) {
			data[i]=f(data[i<<1],data[i<<1|1]);
		}
	}
	M get(int i) {
		return data[n+i];
	}
	M query(int l, int r) {
		M L=I, R=I;
		l+=n; r+=n;
		while(r>l) {
			if(l&1) L=f(L,data[l++]);
			if(r&1) R=f(data[--r],R);
			l>>=1; r>>=1;
		}
		return f(L,R);
	}
};


signed main() {
	int n,k,q;
	std::cin >> n >> k >> q;
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];
	const int INF=1e14;
	int min=INF;
	rep(ii,n) {
		int x=a[ii];
		std::vector<std::pair<int,int> > b;
		for(int i=0;i<n;) {
			while(i<n && a[i]<x) i++;
			int start=i;
			while(i<n && a[i]>=x) i++;
			if(i>start) b.emplace_back(start,i);
		}
		std::vector<int> take;
		for(auto p:b) {
			int l=p.first,r=p.second;
			if(r-l<k) continue;
			std::vector<int> xx;
			for(int i=l;i<r;i++) xx.emplace_back(a[i]);
			std::sort(all(xx));
			rep(i,r-l-k+1) take.emplace_back(xx[i]);
		}
		std::sort(all(take));
		if(take.size()<q) continue;
		min=std::min(min,take[q-1]-x);
	}
	print(min);
	return 0;
}
