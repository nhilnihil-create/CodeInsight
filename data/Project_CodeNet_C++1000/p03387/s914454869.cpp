#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a > b)
		swap(a, b);
	if (a > c)
		swap(a, c);
	if (b > c)
		swap(b, c);
	int x = c - b + (c - (a + c - b) + 1) / 2 + (c - (a + c - b)) % 2;
	cout << x;
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