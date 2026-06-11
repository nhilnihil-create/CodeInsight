#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <utility>
#include <deque>
#include <queue>

#define rep(i, n) for(int i = 0; i < n; ++i)
#define REP(i, m, n) for(int i = m; i < n; ++i)
#define rrep(i,n) for(int i = n; i >= 0; --i)
#define RREP(i, m, n) for(int i = n; i >= m; --i)

using ll = long long;
using ull = unsigned long long;
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;

using namespace std;

const long long MOD = 998244353;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	list<int> b;
	rep(i, n) {
		int t;
		cin >> t;
		b.push_back(t);
	}

	deque<int> ans;
	while (!b.empty()) {
		int num = b.size() - 1;
		
		bool ok = false;
		for (auto itr = b.rbegin(); itr != b.rend(); ++itr) {
			if (*itr == num + 1) {
				ans.push_front(*itr);
				b.erase((++itr).base());
				ok = true;
				break;
			}

			--num;
		}

		if (!ok) {
			cout << -1 << "\n";
			return 0;
		}
	}

	while (!ans.empty()) {
		cout << ans.front() << "\n";

		ans.pop_front();
	}

	return 0; 
}
