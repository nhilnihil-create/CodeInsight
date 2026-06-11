#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
	int n, k;
	cin >> n >> k;
	int ans = 1;
	for (int i = 0; i < n; i++) {
		if (ans + k * (n - i - 1) < k * (n - i))
			ans <<= 1;
		else
			ans += k;
	}
	cout << ans << endl;
}