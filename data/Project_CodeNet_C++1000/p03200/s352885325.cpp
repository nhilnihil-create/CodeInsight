#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string S;
	cin >> S;
	int cb = 0;
	long long ans = 0;
	for (char c : S) {
		if (c == 'B') {
			++cb;
		} else {
			ans += cb;
		}
	}
	cout << ans << '\n';
	
	return 0;
}
