#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, cnt = 0;
void find(ll x) {
	if (x <= n) {
		int t = x;
		int c1 = 0, c2 = 0, c3 = 0;
		while (t > 0) {
			if (t % 10 == 3) c1 = 1;
			if (t % 10 == 5) c2 = 1;
			if (t % 10 == 7) c3 = 1;
			t /= 10;
		}
		if (c1 + c2 + c3 == 3) cnt++;
		find(x * 10 + 3);
		find(x * 10 + 5);
		find(x * 10 + 7);
	}
}

void solve() {
	cin >> n;
	find(0);
	cout << cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t = 1;
	//cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
}