#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)
int main() {
	string s;
	cin >> s;
	deque<char> d;
	for (auto p : s) d.push_back(p);
	int n = s.size(), ans = 0;
	while (true) {
		if (n <= 1) break;
		if (d.front() == d.back()) {
			d.pop_front();
			d.pop_back();
			n -= 2;
		} else if (d.front() == 'x') {
			ans++;
			d.pop_front();
			n--;
		} else if (d.back() == 'x') {
			ans++;
			d.pop_back();
			n--;
		} else {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}