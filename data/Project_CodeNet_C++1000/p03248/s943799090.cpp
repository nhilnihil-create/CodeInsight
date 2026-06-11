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

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ENDL '\n'
#define print(i) std::cout << (i) << '\n'

#define int long long // at least int64 > 9*10^18
#define all(v) (v).begin(), (v).end()
/* libraries */

signed main() {
	std::string s;
	std::cin >> s;
	// check
	int n = s.size();
	if(s.back()=='1' || s.front()=='0') {
		print(-1);
		return 0;
	}
	for(int i=0;i<n/2;i++) {
		if(s[i]!=s[n-2-i]) {
			print(-1);
			return 0;
		}
	}

	std::vector<std::pair<int,int> > g;
	int current = 0;
	rep(i,n-1) {
		if(s[i]=='1') {
			g.emplace_back(i+1,current);
			current = i+1;
		} else {
			g.emplace_back(i+1,current);
		}
	}
	for(auto i:g) {
		std::cout << i.first+1 << ' ' << i.second+1 << '\n';
	}
	return 0;
}
