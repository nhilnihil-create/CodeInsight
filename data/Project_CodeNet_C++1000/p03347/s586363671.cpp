#include<iostream>
#include<string>
#include<algorithm>	
#include<cmath>
using namespace std;
int main() {
	long long n, a, b = 0, ans = 0; cin >> n;
	int test[223456] = { 0 };
	for (int h = 0; h < n; h++) {
		cin >> a; test[h] = a;
		if (h == 0 && a != 0) {
			cout << -1 << endl; cin >> n; return 0;
		}
		if (test[h] > test[h - 1] + 1 && h != 0) {
			cout << -1 << endl; cin >> n; return 0;
		}
		if (b == 0) {
			b = test[h];
		}
		else if (test[h - 1] + 1 == test[h]) {
			b = test[h];
		}
		else {
			ans += b; b = test[h];
		}
	}
	ans += b;
	cout << ans << endl;
	cin >> n;
}