#include <iostream>
#include <vector>
#include <algorithm>
#include <valarray>
#include <array>

using namespace std;

int main() {
	int n, d, x, ans, temp;
	cin >> n >> d >> x;
	d--;
	ans = x;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		ans += (d / temp + 1);
	}
	cout << ans << endl;
}