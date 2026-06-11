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

#define int long long // at least int64 > 9*10^18
#define ENDL '\n'
#define rep(i,n) for(int i = 0; i < (n); i++)
#define print(i) std::cout << (i) << '\n'
#define all(v) (v).begin(), (v).end()
/* libraries */

signed main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	rep(i,n) std::cin >> a[i];
	std::vector<int> ac(n);
	ac[0] = a[0];
	rep(i,n-1) ac[i+1] = ac[i] + a[i+1];
	std::vector<int> A(n,-1);
	{
		int l = 0;
		for(int r=1;r<n-2;r++) {
			while(std::abs(2*ac[l+1]-ac[r])<std::abs(2*ac[l]-ac[r])) l++;
			A[r] = l;
		}
	}
	debug(A);
	std::vector<int> bc(n);
	bc[0] = a[n-1];
	rep(i,n-1) bc[i+1] = bc[i] + a[n-2-i];
	debug(bc);
	std::vector<int> B(n,-1);
	{
		int l = 0;
		for(int r=1;r<n-2;r++) {
			while(std::abs(2*bc[l+1]-bc[r])<std::abs(2*bc[l]-bc[r])) l++;
			B[r] = l;
		}
	}
	debug(B);
	const int INF = 1e18;
	int min = INF;
	for(int i=1;i<n-2;i++) {
		int fi,se,th,fo;
		fi = ac[A[i]];
		se = ac[i]-fi;
		th = bc[B[n-2-i]];
		fo = bc[n-2-i] - th;
		debug(fi,se,th,fo);
		min = std::min(min, std::max({fi,se,th,fo}) - std::min({fi,se,th,fo}));
	}
	print(min);

	return 0;
}
