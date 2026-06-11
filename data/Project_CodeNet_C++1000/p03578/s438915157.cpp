#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	priority_queue<ll, vector<ll>, greater<ll>>d,t;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		d.push(x);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		ll x;
		cin >> x;
		t.push(x);
	}
	while (t.size() >= 1) {
		if (d.top() < t.top())d.pop();
		else if (d.top() == t.top()) {
			d.pop();
			t.pop();
		}
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;

}