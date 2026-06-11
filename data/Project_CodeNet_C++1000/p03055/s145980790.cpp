#include <iostream> // cin, cout, cerr, clog
#include <algorithm> // minmax, sort, swap
#include <numeric> // iota, accumulate, inner_product
#include <cstdio> // printf, scanf
#include <climits> // INT_MIN, LLONG_MIN
#include <cmath> // long, trig, pow
#include <string> // string, stoi, to_string
#include <vector> // vector
#include <queue> // queue, priority_queue
#include <deque> // deque
#include <stack> // stack
#include <map> // key-value pairs sorted by keys
#include <set> // set
#include <unordered_map> // hashed by keys
#include <unordered_set> // hashed by keys
#include <iomanip> // cout<<setprecision(n)
#include <functional> // std::function<void(int)>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ENDL '\n'
#define print(i) std::cout << (i) << '\n'

#define int long long // at least int64 > 9*10^18
#define all(v) (v).begin(), (v).end()
/* libraries */

signed main() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int> > t(n,std::vector<int>());
	rep(i,n-1) {
		int a,b;
		std::cin >> a >> b;
		a--;b--;
		t[a].emplace_back(b);
		t[b].emplace_back(a);
	}

	int v=0; // maxi
	int fmaxd=0; // first max
	std::vector<int> went(n,0);
	std::function<void(int,int)> dfs = [&] (int i, int d) {
		went[i]=true;
		if(fmaxd<d) {
			fmaxd = d;
			v = i;
		}
		for(auto to:t[i]) {
			if(!went[to]) {
				dfs(to,d+1);
			}
		}
	};
	dfs(0,0);
	rep(i,n) went[i] = false;
	dfs(v,0);
	if(fmaxd%3==1) {
		print("Second");
	} else {
		print("First");
	}

	return 0;
}
