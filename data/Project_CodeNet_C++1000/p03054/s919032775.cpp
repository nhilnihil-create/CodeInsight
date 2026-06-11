#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

typedef long long LL;
 
const int OO = 1e9;
const int MOD = 1e9 + 7;

class Task {
public:

	void solve() {
		int h, w, n;
		cin >> h >> w >> n;
		int x, y;
		cin >> x >> y;
		string s, t;
		cin >> s >> t;
		
		int r, c;
		
		c = y;
		for (int j = 0 ; j < n; ++j) {
			if (s[j] == 'R') {
				c++;
			}
			if (c > w) {
				cout << "NO\n";
				return;
			}
			if (t[j] == 'L' && c > 1) {
				--c;
			}
		}
		
		c = y;
		for (int j = 0 ; j < n; ++j) {
			if (s[j] == 'L') {
				c--;
			}
			if (c < 1) {
				cout << "NO\n";
				return;
			}
			if (t[j] == 'R' && c < w) {
				++c;
			}
		}
		
		r = x;
		for (int j = 0 ; j < n; ++j) {
			if (s[j] == 'U') {
				r--;
			}
			if (r < 1) {
				cout << "NO\n";
				return;
			}
			if (t[j] == 'D' && r < h) {
				++r;
			}
		}
		
		r = x;
		for (int j = 0 ; j < n; ++j) {
			if (s[j] == 'D') {
				r++;
			}
			if (r > h) {
				cout << "NO\n";
				return;
			}
			if (t[j] == 'U' && r > 1) {
				--r;
			}
		}
		
		cout << "YES\n";
	}
};
 
int32_t main() {
//~ #ifndef ONLINE_JUDGE
	//~ freopen("input.txt", "r", stdin);
//~ #endif
 
	Task *task = new Task();
	task->solve();
	return 0;
}
