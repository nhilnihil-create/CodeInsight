#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
	int N;
	cin >> N;

	ll ans = 1;
	if (N == 1) {
		ans = 1;
	}

	ll pre2 = 2; 
	ll pre1 = 1;

	for (int i = 2; i <= N; ++i) {
		ll L = pre1 + pre2;
		pre2 = pre1;
		pre1 = L;
	}
	ans = pre1;
	
	cout << ans << endl;
	return 0;
}