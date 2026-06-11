#include <bits/stdc++.h>
using namespace std;
using P = pair<int, int>;

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int sum = 0;
		int temp = i;
		while (temp) {
			sum += temp % 10;
			temp /= 10;
		}
		if (sum >= a && sum <= b) ans += i;
	}
	cout << ans << endl;
}