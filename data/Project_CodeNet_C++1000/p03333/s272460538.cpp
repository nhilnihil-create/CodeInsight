#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;



int main() {
#ifdef LC
	assert(freopen("input.txt", "r", stdin));
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	priority_queue<int> l, r;
	l.push(0);
	r.push(0);
	while (n--) {
		int a, b;
		cin >> a >> b;
		l.push(a);
		r.push(-b);
	}
	ll answer = 0;
	while (l.size()) {
		answer += max(0, l.top() + r.top());
		l.pop();
		r.pop();
	}
	cout << 2 * answer << "\n";
	return 0;
}
