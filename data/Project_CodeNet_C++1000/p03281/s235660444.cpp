#include<iostream>
using namespace std;

int calc(int x) {
	int cnt = 0;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0)cnt++;
	}
	return cnt;
}

int main() {
	int n; cin >> n;

	int ans = 0;
	for (int i = 1; i <= n; i += 2) {
		int cnt = calc(i);
		if (cnt == 8)ans++;
	}
	cout << ans << endl;

	return 0;
}