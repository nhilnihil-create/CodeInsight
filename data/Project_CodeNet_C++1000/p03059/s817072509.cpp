#include <bits/stdc++.h>

using namespace std;

#define ll long long




void solve() {

	int a, b, t;
	cin >> a >> b >> t;
	int x = a;
	int total = 0;
	while(x <= t + 0.5) {
		total += b;
		x += a;

	}
	cout << total;

	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	solve();

	return 0;
}