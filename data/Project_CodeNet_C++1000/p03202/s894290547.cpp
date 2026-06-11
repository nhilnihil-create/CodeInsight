#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define all(x) begin(x), end(x)
#define x first
#define y second
typedef long long ll;
typedef long double ld;

template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T>
using normal_queue = priority_queue<T, vector<T>, greater<T>>;

const int MAX_N = 2e5 + 10;

int a[MAX_N];

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	bool oneflag = 1;
	for (int i = 1; i < n; ++i) {
		if (a[i - 1] >= a[i]) {
			oneflag = 0;
		}
	}
	if (oneflag)
		return cout << "1\n", 0;
	int l = 1, r = n;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		bool flag = 1;
		// cout << "checking for " << mid << ":" << endl;
		vector<pair<int, int>> current;
		for (int i = 1; i < n; ++i) {
			// cout << "at " << i << ": ";
			// for (auto p : current)
			// 	cout << p.x << ":" << p.y << " ";
			// cout << "\n";
			if (a[i - 1] < a[i])
				continue;
			while (current.size() && current.back().x >= a[i])
				current.pop_back();
			int cnt = a[i] - 1;
			while (current.size() && current.back().x == cnt && current.back().y == mid - 1) {
				current.pop_back();
				--cnt;
			}
			// cout << cnt << "\n";
			if (cnt == -1) {
				flag = 0;
				break;
			}
			if (current.size() && current.back().x == cnt) {
				++current.back().y;
			} else {
				current.push_back({cnt, 1});
			}
		}
		// for (auto p : current)
		// 	cout << p.x << ":" << p.y << " ";
		// cout << "\n";
		// cout << "result " << flag << endl;
		if (flag)
			r = mid;
		else
			l = mid;
	}
	cout << r << "\n";
	return 0;
}