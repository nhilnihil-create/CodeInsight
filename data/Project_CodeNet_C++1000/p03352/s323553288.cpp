#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int ans = 1;
	for (int i = 2; i <= n; i++) {
		int t = i;
		while (t * i <= n) {
			t *= i;
			ans = max(ans, t);
		}
	}
	cout << ans << endl;
}